#pragma once

#include "ASTNode.h"
#include "Symbols.h"
#include "SymbolTable.h"

class SemanticError : public exception
{
	const char* what() const noexcept {}
};

class Semantics : public SymbolTable
{
public:
	Semantics() : SymbolTable() {};
	Semantics(ASTNode *&ast) : ast(ast) {};

	/*
	Adds identifier symbol to current scope. *Use only for identifiers*
	*/
	void AddSymbol(Symbol*& sym) {
		(*GetCurrentScope())[sym->id] = sym;
	}

	/*
	Creates a new symbol in current scope.
	*/
	Symbol* NewSymbol(ASTNode*& node)
	{
		Symbol* sym = new Symbol;
		node->symbol = sym;
		return sym;
	}

	~Semantics() {};

	ASTNode *ast;
};

