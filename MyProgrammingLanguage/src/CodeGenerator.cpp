#include "CodeGenerator.h"

void CodeGenerator::Generate()
{
	Build(ast);
}

/*
Build from operators/keywords only.
Cannot call Build from non-operators/keywords.
*/
void CodeGenerator::Build(ASTNode*& parent)
{
	for (vector<ASTNode*>::iterator it = parent->children.begin(); it != parent->children.end(); ++it)
	{
		// Every single inital node is a special one :).
		BuildSpecialNode(*it);
	}
}

bool CodeGenerator::IsInReference(Symbol*& sym)
{
	for (int i = 0; i < dataReference.size(); i++)
	{
		ReferenceEntry entry = dataReference[i];
		if (entry.sym == sym)
			return true;
	}

	return false;
}


ReferenceEntry CodeGenerator::GetFromReference(Symbol*& sym)
{
	for (int i = 0; i < dataReference.size(); i++)
	{
		ReferenceEntry entry = dataReference[i];
		if (entry.sym == sym)
			return entry;
	}
}

/*
idea:

Statement: a = 1 + b

"=" node:
	"+" node:
		1 node
		b node

We find "=" node first, then process any specials ("+"), and take the current storage index and assign to a.

*/
void CodeGenerator::BuildSpecialNode(ASTNode*& node) 
{
	// new stringstream for every node.
	// that way, when we complete a branch, we are able to commit by adding to this->buffer.

	//stringstream ss;
	Token* token = node->token;

	// Continue down the line & evaluate
	for (int i = 0; i < node->children.size(); i++)
	{
		ASTNode* child = node->children[i];
		// If not is special
		if (!child->IsTokenSpecial()) // Otherwise
		{
			Symbol* sym = child->symbol;

			if (sym->kind == SymbolKind::literal)// Is a literal
			{
				store(child);
			}
		}
	}

	// These are special tokens so find command.
	(this->*(CGCommands[token->type].func))(node);
}

void CodeGenerator::ProcessAnySpecials(ASTNode*& node)
{
	// Process any specials
	for (int i = 0; i < node->children.size(); i++)
	{
		ASTNode* child = node->children[i];
		// If is special
		if (child->IsTokenSpecial())
		{
			// build child
			BuildSpecialNode(child);
		}
	}
}

void CodeGenerator::load(ASTNode*& node)
{
	ProcessAnySpecials(node);

	for (int i = 0; i < node->children.size(); i++) {
		ASTNode* child = node->children[i];
		// will only be one child that's not special so...
		if (!child->IsTokenSpecial())
		{
			Symbol* sym = child->symbol;

			if (sym->kind == SymbolKind::variable)
			{
				int useIndex = indexBuffer.size() - 1; // latest storage index used

				// Add to reference table
				ReferenceEntry ref{
					sym,
					useIndex
				};

				dataReference.push_back(ref);
			}
		}
	}
}

void CodeGenerator::store(ASTNode*& node)
{
	Symbol* sym = node->symbol;
	int useIndex = indexBuffer.size();

	switch (sym->datatype)
	{
	case SymbolDataType::number:
		buffer << "nstore(" << node->token->payload << ")";
		break;
	case SymbolDataType::string:
		buffer << "sstore(" << node->token->payload << ")";
		break;
	}

	buffer << "[" << useIndex << "]\n";
	// input latest storage index
	indexBuffer.push_back(useIndex);

	// Add to storageRefTable
	ReferenceEntry ref {
		sym,
		useIndex
	};
	dataReference.push_back(ref);
}

void CodeGenerator::print(ASTNode*& node)
{
	ProcessAnySpecials(node);

	ASTNode* child = node->children[0];

	int toPrint;
	if (child->IsTokenSpecial())
		toPrint = indexBuffer[indexBuffer.size() - 1]; // latest result
	else
		toPrint = GetFromReference(child->symbol).index;

	buffer << "print(" << toPrint << ")[]\n";;
}

void CodeGenerator::add(ASTNode*& node)
{
	// Process any specials
	ProcessAnySpecials(node);
	// now everything is evaluated
	// take current storage index(stored result) and the child

	stringstream ss;

	ss << "add(";

	// + will only have two children.
	ASTNode* A = node->children[0];
	ASTNode* B = node->children[1];

	// If A is special & B is not
	if ((A->IsTokenSpecial() && !B->IsTokenSpecial())){
		// Get latest result
		int result = indexBuffer[indexBuffer.size() - 1];
		// Get symbol of B
		Symbol* Bsym = B->symbol;
		ReferenceEntry ref = GetFromReference(Bsym);
		
		ss << ref.index << "," << result;
	}

	// Or if B is special & A is not
	if (B->IsTokenSpecial() && !A->IsTokenSpecial()) {
		int result = indexBuffer[indexBuffer.size() - 1];
		// Get symbol of A
		Symbol* Asym = A->symbol;
		ReferenceEntry ref = GetFromReference(Asym);

		ss << ref.index << "," << result;
	}

	// If both children are special, then get latest two results and add then together
	if (A->IsTokenSpecial() && B->IsTokenSpecial()) {
		int result1 = indexBuffer[indexBuffer.size() - 1];
		int result2 = indexBuffer[indexBuffer.size() - 2];
		ss << result1 << "," << result2;
	}

	// If both children aren't special, then get references from both
	if (!A->IsTokenSpecial() && !B->IsTokenSpecial()) {
		// Get symbol of A
		Symbol* Asym = A->symbol;
		ReferenceEntry Aref = GetFromReference(Asym);
		// Get symbol of B
		Symbol* Bsym = B->symbol;
		ReferenceEntry Bref = GetFromReference(Bsym);

		ss << Aref.index << "," << Bref.index;
	}

	int useIndex = indexBuffer.size();
	ss << ")[" << useIndex << "]";

	// push as latest storage index
	indexBuffer.push_back(useIndex);

	buffer << ss.str() << "\n";
}