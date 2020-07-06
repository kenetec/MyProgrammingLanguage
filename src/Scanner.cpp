#include "Scanner.h"

Scanner::Scanner(string filename)
{
	// We use the ifstream here since it has all the functions we need at hand.
	filestream = ifstream();
	filestream.open(filename);

	if (filestream.is_open())
	{
		lineIndex = 0;
		colIndex = -1;
		sourceIndex = -1;
	}
	else
	{
		cerr << "Failed to open " + filename << endl;
	}
}

Character Scanner::Get()
{
	// Check if we've reach eof
	if (!filestream.eof())
	{
		// Get character
		char c = filestream.get();

		// Line and column index check
		// Newline
		if (c == '\n')
		{
			++lineIndex;
			colIndex = -1;
		}

		// Increment column
		++colIndex;

		// Return character
		return Character(c, lineIndex, colIndex, filestream.tellg());
	}
	else 
	{
		// Return ENDMARK character
		return Character(ENDMARK, lineIndex, colIndex, filestream.tellg());
	}
}

char Scanner::Peek(int offset)
{
	char peeked;

	if (offset != 1) 
	{
		// Get original position
		int originalPos = filestream.tellg();
		// Jump to offset position
		filestream.seekg(originalPos + offset);
		// Get peeked character
		peeked = filestream.get();
		// Jump back
		filestream.seekg(originalPos);
	}
	else 
	{
		peeked = filestream.peek();
	}

	return peeked;
}


Scanner::~Scanner()
{
	filestream.close();
}
