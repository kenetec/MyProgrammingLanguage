#pragma once

#include "Lexer.h"
#include "ASTNode.h"
#include "Semantics.h"

class ParserException : public exception
{
	const char* what() const noexcept
	{}
};


/*
Uses recursive-decent parsing.
*/
class Parser
{
public:
	Parser(string filename) : lexer(filename), semantics()
	{}

	ASTNode* Parse() {
		// Get first token
		GetToken();

		// Start program
		return Program();
	}

	~Parser() { delete token; };

	Semantics semantics;

private:
	/*
	Get next token retrieved by lexer.
	*/
	void GetToken();

	/*
	Simplified Error
	*/
	inline void Error(string msg) { lexer.Abort(*token, msg); }

	/*
	Sees if the current token type corresponds to one of the given tokenTypes.
	*/
	bool FoundOneOf(vector<string> tokenTypes);

	/*
	Sees if the current token type corresponds to given token type.
	*/
	bool Found(string tokenType);

	/*
	Sees if string is in vector.
	*/
	bool StrInVec(vector<string>& vec, string& value);

	/*
	Consumes token of given type and retrieves next.

	If current token is not of given type then will throw error.
	*/
	void Consume(string tokenType);

	/*
	Starts entire parse program + AST (y'know nothing major).

	program = block, EOF
	*/
	ASTNode* Program();

	/*
	Blocks create new scopes.

	block = ? '{' ? {statement | block} ? '}' ? 
	*/
	void Block(ASTNode *&node);

	/*
	statement =
		variable_list '=' expression_list |
		function_call |

	statement = assignmentStatement | functionDefineStatement | functionCallStatement | printStatement

	assignmentStatement = [return_type] identifier "=" expression
	functionDefineStatement = [return_type] identifier "(" expression ")" "{" statement "}"
	functionCallStatement = identifier "(" expression ")"

	printStatement = "print" ["("] expression [")"]

	*/
	void Statement(ASTNode *&node);

	/*
	printStatement = "print" ["("] expression [")"]
	*/
	void PrintStatement(ASTNode *&node);

	/*
	assignmentStatement = identifier "=" expression
	*/
	void AssignmentStatement(ASTNode *&node);

	/*
	expression = stringExpression | numberExpression

	stringExpression = (stringLiteral | variable) {"+" stringExpression}
	numberExpression = (numberLiteral | variable) {NumberOperator numberExpression}
	*/
	void Expression(ASTNode *&node, Symbol*& sym);

	/*
	stringExpression = (stringLiteral | variable) {"+" stringExpression}
	*/
	void StringExpression(ASTNode *&node, Symbol*& sym);

	/*
	@ StringConcatenateChar

	stringConcatenate = tok "+" stringExpression
	*/
	void StringConcatentate(ASTNode *&node, Token *&tok, Symbol*& sym);
	void StringConcatentate(ASTNode *&node, Token *&tok, Symbol*& sym, Symbol*& idSym);

	/*
	numberExpression = (numberLiteral | variable) {NumberOperator numberExpression}
	*/
	void NumberExpression(ASTNode *&node, Symbol*& sym);

	/*
	@ NumberOperator
	numberOperation = tok NumberOperator numberExpression
	*/
	void NumberOperation(ASTNode *&node, Token *&tok, Symbol*& sym);
	void NumberOperation(ASTNode *&node, Token *&tok, Symbol*& sym, Symbol*& idSym);

	/*
	stringLiteral is just the string itself.
	*/
	void StringLiteral(ASTNode*& node);

	/*
	numberLiteral is just the number itself.
	*/
	void NumberLiteral(ASTNode*& node);

	Lexer lexer;
	Token *token;
	//Semantics semantics;
};

