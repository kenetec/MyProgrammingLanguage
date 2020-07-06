#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

class Token
{
public:
	Token(Character startChar)
	{
		payload = startChar.character;
		lineIndex = startChar.lineIndex;
		colIndex = startChar.colIndex;
	}

	Token(const Token &toCopy) 
	{
		payload = toCopy.payload;
		lineIndex = toCopy.lineIndex;
		colIndex = toCopy.colIndex;
		type = toCopy.type;
	}

	string ToString();

	inline string GetPayload() {
		return payload;
	};

	inline void AddToPayload(string c) {
		payload += c;
	}

	~Token() {};

	string payload;
	int lineIndex;
	int colIndex;
	// Token type: unknown until lexer processes token and assigns type.
	string type;
};

