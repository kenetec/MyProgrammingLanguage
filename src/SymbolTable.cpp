#include "SymbolTable.h"

SymbolTable::SymbolTable()
{}

Scope* SymbolTable::NewScope()
{
	if (scopes.empty())
	{
		Scope* globalScope = new Scope;
		globalScope->parentScopeIndex = 0; // global scope parent is itself(the end all, be all)
		globalScope->scopeIndex = 0;

		scopes.push_back(globalScope);
		currentScopeIndex = globalScope->scopeIndex;;

		return globalScope;
	}
	else
	{
		Scope* scope = new Scope;

		scope->parentScopeIndex = currentScopeIndex;
		scope->scopeIndex = scope->parentScopeIndex + 1;

		scopes.push_back(scope);
		currentScopeIndex = scope->scopeIndex;

		return scope;
	}
}

/*void SymbolTable::AddScope(Scope *&scope)
{
	scopes.push_back(scope);
}*/

Scope* SymbolTable::GetScope(int index)
{
	return scopes[index];
}

/*void SymbolTable::SetCurrentIndex(int index)
{
	currentScopeIndex = index;
}*/

Scope* SymbolTable::GetCurrentScope()
{
	return scopes[currentScopeIndex];
}

void SymbolTable::LeaveCurrentScope()
{
	currentScopeIndex = GetCurrentScope()->parentScopeIndex;
	scopes.pop_back();
}

Symbol* SymbolTable::GetSymbol(string symId)
{
	return GetSymbolOfScope(symId, currentScopeIndex);
}

Symbol* SymbolTable::GetSymbolOfScope(string symId, int index)
{
	Scope *scope = GetScope(index);

	if ((*scope).find(symId) != (*scope).end())
	{
		Symbol* sym = (*scope)[symId];
		return sym;
	}
	else if (index == scope->parentScopeIndex) // is global scope
	{
		// we need to error b/c the symbol doesn't exist.
		cerr << symId << " does not exist!" << endl;
	}
	else {
		return GetSymbolOfScope(symId, scope->parentScopeIndex); // Go to parent scope
	}
}

string SymbolTable::ToString()
{
	stringstream ss;

	int scopeIndex = 0;
	for (vector<Scope*>::iterator scopeIt = scopes.begin(); scopeIt != scopes.end(); ++scopeIt)
	{
		Scope* scope = *scopeIt;

		ss << "[" << scopeIndex << " (" << scope->parentScopeIndex << ")]\n";

		int symIndex = 0;
		for (SymbolHash::iterator symIt = scope->begin(); symIt != scope->end(); ++symIt)
		{
			Symbol* sym = symIt->second;

			ss << "\t" << symIt->first << "\n";

			symIndex++;
		}

		scopeIndex++;
	}

	return ss.str();
}

string SymbolTable::ToStringPretty()
{
	return "";
}

bool SymbolTable::IsASymbol(string symId) 
{
	return IsASymbolOfScope(symId, currentScopeIndex);
}

bool SymbolTable::IsASymbolOfScope(string symId, int index) 
{
	Scope *scope = GetScope(index);

	bool found = false;

	if ((*scope).find(symId) != (*scope).end())
		found = true;

	return found;
}

SymbolTable::~SymbolTable()
{

}
