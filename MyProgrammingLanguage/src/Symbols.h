#pragma once

#include <vector>

namespace
{
	vector<string> Keywords = {
		"if", 
		"elseif", 
		"else",
		"while",
		"do",
		"for",
		"in", 
		"as", 
		"is",
		"return",
		"print",
		"import",
		"from",
		"class",
	};

	vector<string> OneCharacterSymbols = {
		"=",
		"+", "-", "*", "/", "%", "^",
		"(", ")", "{", "}",
		"!",
		".", ",",
		"?", ":",
		"<", ">",
		";", 
		"$",
	};

	vector<string> TwoCharacterSymbols = {
		"==", "<=", ">=", "!=", 
		"++", "--", 
		"*=", "/=", "+=", "-=", "^=", "%=",
		"=>",
	};

	vector<string> NumberOperators = { 
		"+", "-", "*", "/", "^", "%", 
		"+=", "-=", "*=", "/=", "^=", "%=" };

	string StringStartChars = "\"'";
	string WhitespaceChars = " \t\n";
	string MultiLineCommentStart = "/*";
	string MultiLineCommentEnd = "*/";
	string SingleLineCommentStart = "//";
	string SingleLineCommentEnd = "\n";
	string StringConcatenateChar = "+";
	string BlockStartChar = "{";
	string BlockEndChar = "}";


	string IdentifierStartChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	string IdentifierChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
	string NumberStartChars = "0123456789";
	string NumberChars = "0123456789.exabcdefXABCDEF";

	
	// Type definitions

	// enum class DataTypes { string, number, identifier, whitespace, comment, eof }
	string STRING = "string";
	string NUMBER = "number";
	string IDENTIFIER = "identifier";
	string WHITESPACE = "whitespace";
	string COMMENT = "comment";
	string eof = "eof";
}