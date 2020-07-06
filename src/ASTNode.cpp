#include "ASTNode.h"

ASTNode* ASTNode::Add(Token& token)
{
	ASTNode* node = new ASTNode(token);
	Add(node);
	return node;
}

ASTNode* ASTNode::Add(Token *&token)
{
	ASTNode *node = new ASTNode(*token);
	Add(node);
	return node;
}

ASTNode* ASTNode::Add(Token& token, Scope*& scope)
{
	ASTNode* node = new ASTNode(token);
	Add(node); 
	node->scope = scope;
	return node;
}

ASTNode* ASTNode::Add(Token*& token, Scope*& scope)
{
	return Add(*token, scope);
}

void ASTNode::Add(ASTNode*& node) // get reference of pointer
{
	node->SetLevel(level + 1);
	node->scope = this->scope;
	children.push_back(node);
}

void ASTNode::Add(ASTNode*& node, Scope*& scope)
{
	Add(node);
	node->scope = scope;
}

void ASTNode::SetLevel(int lvl)
{
	level = lvl;
	for (ASTNode* child : children)
		child->SetLevel(level + 1);
}

string ASTNode::ToString()
{
	stringstream ss;

	ss << level;

	// Indent
	for (int i = 0; i < level; i++)
		ss << "\t";

	if (token == nullptr)
		ss << " ROOT\n";
	else
		ss << token->GetPayload() << "\n";

	for (ASTNode* child : children)
		ss << child->ToString();

	return ss.str();
}