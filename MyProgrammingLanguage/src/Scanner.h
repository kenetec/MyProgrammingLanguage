#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Character.h"

using namespace std;

class Scanner
{
public:
	Scanner(string filename);

	Character Get();
	char Peek(int offset = 1);

	~Scanner();


	ifstream filestream;
	int lineIndex;
	int colIndex;
	int sourceIndex;
};

