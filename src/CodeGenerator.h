#pragma once

#include <sstream>
#include <map>

#include "Parser.h"

/*
Command format:

command_name "(" storage indexes..."," ")" "[" return storage index "]"

ex:
	nstore(1)[0]
	nstore(2)[1]
	add(0,1)[2]
	print(2)[]
	sstore(done)[3]
	print(3)[]

*/
/*
All CGCommands:

*** store
	Resolves which store command to use for given data.

nstore(data)[@]
	Stores data of type Number to storage index @.

sstore(data)[@]
	Stores data of type String to storage index @.

*** load
	"="
	From assignment operator, creates an reference entry of the storage index data table.

add(x,y)[@]
	"+"
	Addition operator, returns result on top of stack.
	
print(x)[]
	"print"
	Prints whatever.

*/

class CodeGenerator;

struct CGCommandStruct
{
	string id;
	void(CodeGenerator::*func) (ASTNode*&);
};


struct ReferenceEntry 
{
	Symbol* sym; // symbol
	int index; // reference to index
};

using CGCommand = pair<string, CGCommandStruct>;

/*
Generates a list of commands that will be executed by virutal machine.
*/
class CodeGenerator
{
public:
	CodeGenerator(string filename) : parser(filename) 
	{
		ast = parser.Parse();
	};

	/*
	Generate intermediary code from AST.
	Will be executed by virtual machine.
	*/
	void Generate();

	~CodeGenerator() {};

	ASTNode *ast;
	stringstream buffer;

	Parser parser;
private:
	// Grand build process
	void Build(ASTNode*& parent);
	// Build special tokens
	void BuildSpecialNode(ASTNode*& node);
	// Process any special children of node.
	void ProcessAnySpecials(ASTNode*& node);
	// Gets reference of symbol
	ReferenceEntry GetFromReference(Symbol*& sym);
	// Checks if symbol exists in reference
	bool IsInReference(Symbol*& sym);
	
	/***
	Commands START
	***/

	/*
	Creates a reference entry for identifier node.

	node being "="
	*/
	void load(ASTNode*& node);

	/*
	A generic function that resolves which store function to use for the literal node.

	node being a literal.
	*/
	void store(ASTNode*& node);

	/* 
	add(x, y)[@]
	
	Adds the two numbers at storage indexes x & y and stores result in storage index z.

	node being "="
	*/
	void add(ASTNode*& node);

	// print (storage index)
	void print(ASTNode*& node);

	/***
	Commands END
	***/

	// Current indexes for other functions to use: i.e. add() sets current 
	// storage index to 3, load uses current reference index and current storage index.
	//int currentStorageIndex = 0;

	// Buffer for latest storage indexes
	vector<int> indexBuffer;

	// Reference table for all data (index -> {symbol, storage index})
	vector<ReferenceEntry> dataReference;

	map<string, CGCommandStruct> CGCommands
	{
		CGCommand("=", CGCommandStruct {"load", &CodeGenerator::load}),
		CGCommand("+", CGCommandStruct {"add", &CodeGenerator::add}),
		CGCommand("print", CGCommandStruct {"print", &CodeGenerator::print}),
	};
};

