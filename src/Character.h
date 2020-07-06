#pragma once

#include <iostream>
#include <sstream>

#define ENDMARK '\0'

using namespace std;

class Character
{
public:
	Character(char character, int lineIndex, int colIndex, int sourceIndex) 
		: character(character), lineIndex(lineIndex), colIndex(colIndex), sourceIndex(sourceIndex) {}

	Character() {};
	
	string ToString() 
	{
		stringstream ss;
		ss << lineIndex << "\t\t";
		ss << colIndex << "\t\t";
		ss << character;
		
		return ss.str();
	}

	~Character() {};

	char character;
	int lineIndex;
	int colIndex;
	int sourceIndex;
};

