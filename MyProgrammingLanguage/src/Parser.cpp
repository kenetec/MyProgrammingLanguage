#include "Parser.h"

string dq(string s){ return "\"" + s + "\""; }

void Parser::GetToken()
{
	Token temp = lexer.Get();

	if (temp.type != WHITESPACE && temp.type != COMMENT)
		token = new Token(temp);
	else
		GetToken();
}

bool Parser::FoundOneOf(vector<string> tokenTypes)
{
	if (StrInVec(NumberOperators, token->type))
		return true;
	else
		return false;
}

bool Parser::Found(string tokenType)
{
	if (tokenType == token->type)
		return true;
	else
		return false;
}

bool Parser::StrInVec(vector<string>& vec, string& value)
{
	return (find(vec.begin(), vec.end(), value) != vec.end());
}

void Parser::Consume(string tokenType)
{
	// Simply get next token
	if (Found(tokenType))
		GetToken();
	else
		Error("I was expecting to find " + dq(tokenType) + " but instead I found " + token->ToString());
}

ASTNode* Parser::Program()
{
	// Empty root node
	ASTNode *root = new ASTNode;

	Scope *globalScope = semantics.NewScope();
	
	root->scope = globalScope;

	while (!Found(eof))
	{
		if (Found(BlockStartChar))
			Block(root);
		else
			Statement(root);
	}

	// Last thing to consume of the end of the file
	Consume(eof);

	return root;
}

void Parser::Block(ASTNode *&node)
{
	// create new scope
	Scope* scope = semantics.NewScope();
	ASTNode* blockNode = node->Add(token, scope);

	Consume(BlockStartChar);

	while (!Found(BlockStartChar) && !Found(BlockEndChar))
	{ 
		Statement(node);
	}

	if (Found(BlockStartChar))
		Block(node);

	Consume(BlockEndChar);

	// leave scope
	semantics.LeaveCurrentScope();
}

void Parser::Statement(ASTNode*& node)
{
	// print
	if (Found("print"))
	{
		PrintStatement(node);
	}
	else if (Found(IDENTIFIER)) // Funnel
	{
		AssignmentStatement(node);
		/*if (StrInVec(DataTypes, token->type)) // Function define statement(return type is optional)
		{
			// Assignment statement(type is optional)
			if ()

			// Function define statement(return type is optional)

		}
		else
		{

		}*/
	}
}

/*
We won't hard code this later on. We'll have environments and what not.
*/
void Parser::PrintStatement(ASTNode*& node)
{
	// tree:
	// print
	//		expression
	// Statement node.
	ASTNode* statementNode = node->Add(token);

	// consume print
	Consume("print");

	Symbol* sym = semantics.NewSymbol(statementNode);
	sym->id = "print";
	sym->datatype = SymbolDataType::function;
	sym->kind = SymbolKind::function_call;

	// Check for open parentheses
	if (Found("("))
		Consume("(");

	// Get expression
	Expression(statementNode, sym);

	// Check for close parentheses
	if (Found(")"))
		Consume(")");
}

void Parser::AssignmentStatement(ASTNode *&node)
{
	// tree:
	//					=
	// identifier				expression

	// identifier node
	Token *idToken = token;

	Consume(IDENTIFIER);

	// operator node
	ASTNode *operatorNode = node->Add(token);
	Consume("=");

	// Do this before adding identifier node so the level of the operatorNode can be set.
	ASTNode *identifierNode = operatorNode->Add(idToken);

	// Create a new symbol

	//TODO: FIX THIS!
	// New symbols are not being added to table b/c the table holds the pointers, not the actual value itself.
	Symbol* idSym = semantics.NewSymbol(identifierNode);
	idSym->id = idToken->payload;
	idSym->kind = SymbolKind::variable;
	semantics.AddSymbol(idSym);

	Expression(operatorNode, idSym);
}

void Parser::Expression(ASTNode *&node, Symbol*& sym)
{
	if (Found(STRING))
	{
		StringExpression(node, sym);
	}
	else if (Found(NUMBER))
	{
		NumberExpression(node, sym);
	}
	else // will be more flow control later
	{
		Token *idToken = token;

		Symbol* idSym = semantics.GetSymbol(token->payload);

		if (sym->kind == SymbolKind::variable)
		{}

		Consume(IDENTIFIER);

		// string concatenation
		if (Found(StringConcatenateChar) && idSym->datatype == SymbolDataType::string) 
		{
			StringConcatentate(node, idToken, sym, idSym);
		}
		else if(FoundOneOf(NumberOperators) && idSym->datatype == SymbolDataType::number)
		{
			NumberOperation(node, idToken, sym, idSym);
		}
		else
		{
			//Error("Expected expression: " + token->ToString());
			ASTNode* identifierNode = node->Add(idToken);
			identifierNode->symbol = idSym;
		}
	}
}

void Parser::StringConcatentate(ASTNode *&node, Token *&tok, Symbol*& sym)
{
	// Node for concatentation
	ASTNode *concatNode = node->Add(token);
	Consume(StringConcatenateChar);

	// Add string node
	// String literal
	ASTNode *stringNode = concatNode->Add(tok);
	StringLiteral(stringNode);

	// Find next expression.
	StringExpression(concatNode, sym);
}

void Parser::StringConcatentate(ASTNode *&node, Token *&tok, Symbol*& sym, Symbol*& idSym)
{
	// Node for concatentation
	ASTNode *concatNode = node->Add(token);
	Consume(StringConcatenateChar);

	// Add string node
	// String identifier
	ASTNode *stringNode = concatNode->Add(tok);
	stringNode->symbol = &*idSym;

	// Find next expression.
	StringExpression(concatNode, sym);
}

void Parser::StringExpression(ASTNode *&node, Symbol*& sym)
{
	if (Found(STRING))
	{
		// Make node
		Token *stringToken = token;

		if (sym->kind == SymbolKind::variable)
			sym->datatype = SymbolDataType::string;

		Consume(STRING);

		if (Found(StringConcatenateChar))
		{
			StringConcatentate(node, stringToken, sym);
		}
		else 
		{
			ASTNode *stringNode = node->Add(stringToken);
			StringLiteral(stringNode);
		}
	}
	else if (Found(IDENTIFIER))
	{
		Token* idToken = token;

		Symbol* idSym = semantics.GetSymbol(token->payload);
		if (idSym->datatype != SymbolDataType::string)
			Error("\"" + idSym->id + "\" is not a string! ");

		Consume(IDENTIFIER);

		if (Found(StringConcatenateChar))
		{
			StringConcatentate(node, idToken, sym, idSym);
		}
		else
		{
			ASTNode *identifierNode = node->Add(idToken);
			identifierNode->symbol = &*idSym;
		}
	}
	else
		Error("expected string or identifier: " + token->ToString());
}

void Parser::NumberOperation(ASTNode *&node, Token *&tok, Symbol*& sym)
{
	// Add operator
	ASTNode *operatorNode = node->Add(token);

	// Add literal to operatorNode.
	ASTNode *literalNode = operatorNode->Add(tok);
	NumberLiteral(literalNode);

	// Can't consume operator token so skip
	GetToken();

	NumberExpression(operatorNode, sym);
}

void Parser::NumberOperation(ASTNode *&node, Token *&tok, Symbol*& sym, Symbol*& idSym)
{
	// Add operator
	ASTNode *operatorNode = node->Add(token);

	// Add identifier to operatorNode.
	ASTNode *identifierNode = operatorNode->Add(tok);
	identifierNode->symbol = idSym;

	// Can't consume operator token so skip
	GetToken();

	NumberExpression(operatorNode, sym);
}


void Parser::NumberExpression(ASTNode *&node, Symbol*& sym)
{
	if (Found(NUMBER))
	{
		Token *numberToken = token;

		if (sym->kind == SymbolKind::variable)
			sym->datatype = SymbolDataType::number;

		Consume(NUMBER);

		if (FoundOneOf(NumberOperators))
		{
			NumberOperation(node, numberToken, sym);
		}
		else
		{
			ASTNode* numberNode = node->Add(numberToken);
			NumberLiteral(numberNode);
		}
	}
	else if (Found(IDENTIFIER))
	{
		// insert semantics here.
		// verify identifier's existance and data type

		if (sym->kind == SymbolKind::variable)
			sym->datatype = SymbolDataType::number;

		Token *idToken = token;

		Symbol* idSym = semantics.GetSymbol(token->payload);
		if (idSym->datatype != SymbolDataType::number)
			Error("\"" + idSym->id + "\" is not a number! ");


		Consume(IDENTIFIER);

		if (FoundOneOf(NumberOperators))
		{
			NumberOperation(node, idToken, sym, idSym);
		}
		else
		{
			ASTNode* numberNode = node->Add(idToken);
			numberNode->symbol = idSym;
		}
	}
	else
		Error("expected number or identifier: " + token->ToString());
}

// literals are not added to symbol table
void Parser::StringLiteral(ASTNode*& node)
{
	Symbol* sym = semantics.NewSymbol(node);
	sym->id = node->token->payload;
	sym->datatype = SymbolDataType::string;
	sym->kind = SymbolKind::literal; // literals are temporarly stored on the stack(with no particular reference).
	//semantics.AddSymbol(sym);
}

// literals are not added to symbol table
void Parser::NumberLiteral(ASTNode*& node)
{
	Symbol* sym = semantics.NewSymbol(node);
	sym->id = node->token->payload;
	sym->datatype = SymbolDataType::number;
	sym->kind = SymbolKind::literal;
	//semantics.AddSymbol(sym);
}