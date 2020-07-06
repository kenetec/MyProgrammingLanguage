#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

enum class SymbolDataType {
	function,
	number,
	string,
	null,
	table,
	boolean,
	any,
};

enum class SymbolKind {
	function_declaration,
	function_call,
	function_parameter,
	variable,
	class_k,
	literal,
};

class Attribute
{
public:
	Attribute(){}
};

struct Symbol
{
	// Symbol identifier
	string id;
	// Symbol type
	SymbolDataType datatype;
	// Symbol kind(i.e. function parameter, variable, etc.)
	SymbolKind kind;
	// Attributes
	vector<Attribute> attributes;
};


using SymbolHash = unordered_map<string, Symbol*>;
using SymbolHashEntry = pair<string, Symbol*>;

class Scope : public SymbolHash // the string is the symbol identifier
{ 
public:
	// Parent scope index.
	int parentScopeIndex;
	// Own scope index.
	int scopeIndex;
	Scope() {};
};

/*
Idea:
All scopes are in one vector, however, we traverse scopes by going through their parents.
For example: AA Scope is nested in the A Scope which is nested in the Global Scope
	Global
		A
			AA

If scope AA makes a reference to a symbol in the global scope, we work backwards from the AA scope to the Global scope
by following each scope's parent scope index.

AA -> A -> Global

[0] Global scope (parentScopeIndex = 0)
	Symbol a
	Symbol b

[1] A scope (parentScopeIndex = 0)
	Symbol c

[2] AA scope (parentScopeIndex = 1)
	*Reference to symbol a -> go back up the parent line: AA->A->Global*
	*Leave scope; delete AA scope*

[2] AB scope (parentScopeIndex = 1)
	*Reference to symbol c -> parent line: AB->A*
*/
class SymbolTable
{
public:
	/*
	Default Constructor for SymbolTable.

	Creates global scope.
	*/
	SymbolTable();

	/*
	Creates a new scope and nests it inside current scope.
	Sets current scope to newly created scope.
	*/
	Scope* NewScope();

	/*
	Add a scope to scopes table
	*/
	//void AddScope(Scope *&scope);

	/*
	Get scope at given index.
	*/
	Scope* GetScope(int index);

	/*
	Set current scope at index.
	*/
	//void SetCurrentIndex(int index);

	/*
	Gets current scope.
	*/
	Scope* GetCurrentScope();

	/*
	Leave current scope(delete).
	*/
	void LeaveCurrentScope();

	/*
	Searches for symbol through all parent scopes of current scope index.
	*/
	Symbol* GetSymbol(string symId);

	/*
	Searches for symbol through all parent scopes of given scope index.
	*/
	Symbol* GetSymbolOfScope(string symId, int index);

	/*
	Checks if symbol exists in current scope.
	*/
	bool IsASymbol(string symId);

	/*
	Checks if symbol exists in given scope.
	*/
	bool IsASymbolOfScope(string symId, int index);

	/*
	String representation
	*/
	string ToString();

	/*
	Pretty string representation
	*/
	string ToStringPretty();

	~SymbolTable();

	vector<Scope*> scopes;
	int currentScopeIndex;
};

