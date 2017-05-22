#pragma once

#include <vector>

#include "Token.h"
#include "SymbolTable.h"

using namespace std;

/*
Node for Abstract Syntax Tree.
*/
class ASTNode
{
public:
	// For root
	ASTNode() {};

	ASTNode(Token& token)
	{
		this->token = &token;
	}

	/*
	Add Token or Node to children.
	*/
	ASTNode* Add(Token& token);
	ASTNode* Add(Token*& token);
	ASTNode* Add(Token& token, Scope*& scope);
	ASTNode* Add(Token*& token, Scope*& scope);
	void Add(ASTNode*& node);
	void Add(ASTNode*& node, Scope*& scope);

	/*
	Set node level(will change children's levels also)
	*/
	void SetLevel(int lvl);

	/*
	Checks if token is a special one.
	*/
	bool IsTokenSpecial() { return (token->payload == token->type); }

	string ToString();

	~ASTNode() { };

	// Use pointer b/c we cannot initialize immediately.
	Token *token;

	// Depth level in tree.
	int level;

	// Children vector
	// contain pointers so if the pointer alters something after being add, it will still be reflected in the container.
	vector<ASTNode*> children; 

	// pointer to symbol object
	Symbol* symbol;
	// pointer to scope object
	Scope* scope;
};

