#include "Token.h"

string Token::ToString()
{
	stringstream str;
	str << lineIndex << "\t\t";
	str << colIndex << "\t\t";

	if (type == payload)
		str << type << " symbol";
	else
		str << type << ": " << payload;

	return str.str();
}
