#pragma once

#include <vector>
#include <algorithm>

#include "Scanner.h"
#include "Token.h"
#include "Symbols.h"

using namespace std;

// Lexer Error
class LexerError : public exception {
	const char *what() const noexcept {
		return "";
	};
};

class Lexer
{
public:
	Lexer(string filename) : scanner(filename)
	{
		// Get first character
		GetChar();
	}

	Token Get();
	void GetChar();
	void Abort(Token token, string msg);
	bool StrInVec(vector<string>& vec, const string& value);

	~Lexer() {};


	Scanner scanner;
	Character character;
	string c1;
	string c2;
};

