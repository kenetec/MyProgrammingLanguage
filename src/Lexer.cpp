#include "Lexer.h"

/*
Generate and return a token.
*/
Token Lexer::Get()
{
	// Process comments and whitespace //
	// Process whitespace
	if (WhitespaceChars.find(c1) != string::npos)
	{
		// Note: we aren't really gonna use whitespace so making tokens is useless. 
		// Will comment out block in production.
		Token token(character);
		token.type = WHITESPACE;
		// read past whitespace
		GetChar();

		while (WhitespaceChars.find(c1) != string::npos)
		{
			token.AddToPayload(c1);
			GetChar();
		}

		return token;
	}

	// Process comments //
	if (c2 == SingleLineCommentStart)
	{
		// Note: we aren't really gonna use comments so making tokens is useless. 
		// Will comment out block in production.
		Token token(character);
		token.type = COMMENT;

		// Remove '/'
		token.payload.pop_back();

		// read past the two characters
		GetChar(); // *
		GetChar(); // next char

		// Comment ends at \n
		while (c1 != SingleLineCommentEnd)
		{
			if (c1.c_str()[0] == ENDMARK)
				break;

			token.AddToPayload(c1);
			GetChar();
		}

		// Remove '\n'
		// token.payload.pop_back();

		return token;
	}

	if (c2 == MultiLineCommentStart)
	{
		// Note: we aren't really gonna use comments so making tokens is useless. 
		// Will comment out block in production.
		Token token(character);
		token.type = COMMENT;

		// Remove '/'
		token.payload.pop_back();

		// read past the two characters
		GetChar(); // *
		GetChar(); // next char

		while (c2 != MultiLineCommentEnd) 
		{
			token.AddToPayload(c1);
			GetChar();
		}

		// We are currently at the "*" character, so GetChar() twice
		GetChar();
		GetChar();

		// Remove from payload '*'
		//token.payload.pop_back();

		return token;
	}

	// Finish comment & whitespace processing
	// Now start with actual tokens
	Token token(character);

	// Process endmark
	if (c1.c_str()[0] == ENDMARK)
	{
		token.type = eof;
		return token;
	}

	// Process identifiers & keywords
	if (IdentifierStartChars.find(c1) != string::npos)
	{
		token.type = IDENTIFIER;
		GetChar();

		while (IdentifierChars.find(c1) != string::npos)
		{
			token.AddToPayload(c1);
			GetChar();
		}

		// Process keywords //
		if (StrInVec(Keywords, token.GetPayload()))
		{
			// check if keyword; if so, set type as payload
			token.type = token.GetPayload();
		}

		return token;
	}

	// process numbers
	if (NumberStartChars.find(c1) != string::npos) 
	{
		token.type = NUMBER;
		GetChar();

		while (NumberChars.find(c1) != string::npos)
		{
			token.AddToPayload(c1);
			GetChar();
		}

		return token;
	}

	// process string
	if (StringStartChars.find(c1) != string::npos)
	{
		// remember starting quote character
		string startingQuote = c1;
		token.type = STRING;

		// Remove start quote
		token.payload.pop_back();

		// Next char after starting quote character
		GetChar();

		while (c1 != startingQuote)
		{
			if (c1.c_str() == (const char *) ENDMARK)
				Abort(token, "Found end of file before end of string literal");

			token.AddToPayload(c1);
			GetChar();
		}

		// Add in ending quote
		// token.AddToPayload(c1);

		// Next
		GetChar();

		return token;
	}

	// process two char symbols
	if (StrInVec(TwoCharacterSymbols, c2))
	{
		token.payload = c2;
		token.type = token.GetPayload();

		// Skip past c1 + 1
		GetChar();
		// Next char
		GetChar(); 

		return token;
	}

	// process one char symbols
	if (StrInVec(OneCharacterSymbols, c1))
	{
		token.type = token.GetPayload();
		GetChar();

		return token;
	}

	Abort(token, "I found a character or symbol that I do not recognize: \"" + c1 + "\"");
	return token;
}


void Lexer::GetChar()
{
	character = scanner.Get();
	c1 = character.character;
	c2 = c1 + scanner.Peek();
}

bool Lexer::StrInVec(vector<string>& vec, const string& value)
{
	return (find(vec.begin(), vec.end(), value) != vec.end());
}

void Lexer::Abort(Token token, string msg)
{
	cerr << "On line " << token.lineIndex + 1
		<< " near column " << token.colIndex + 1 << ":\n"
		//<< "\"" << token.GetPayload() << "\"\n"
		//<< "^" << msg << endl;
		<< msg << endl;

	cin.get();
	exit(EXIT_FAILURE);
}