#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
using StorageIndex = int;

class VirtualMachine;

struct VMCommandStruct
{
	string id;
	void(VirtualMachine::*func) (vector<StorageIndex> args, vector<string> strargs, StorageIndex returnIndex);
};

using VMCommand = pair<string, VMCommandStruct>;

struct StorageEntry {
	StorageIndex index;
	string datatype;
	int dataIndex;
};

/*
Read and execute generated code.

The virutal machine is independent from everything else, therefore it should not require anything that has to do with
the parsing or code generation.


// Do we really even need a stack?

Goals:
* Read generated code
* Mirror all data
* Execute generated code
*/
class VirtualMachine
{
public:
	VirtualMachine(string filename);

	// Read file
	void Read();

	// Convert char to int('1' -> 1)
	int ToDigit(char c);

	// *** COMMANDS START ***

	void nstore(vector<StorageIndex> args, vector<string> strargs, StorageIndex returnIndex);
	void sstore(vector<StorageIndex> args, vector<string> strargs, StorageIndex returnIndex);
	void add(vector<StorageIndex> args, vector<string> strargs, StorageIndex returnIndex);
	void print(vector<StorageIndex> args, vector<string> strargs, StorageIndex returnIndex);

	// *** COMMANDS END ***
	~VirtualMachine();



	// Reading
	ifstream filestream;
	
	// Execution
	// Vectors for holding storage data.
	vector<StorageEntry> storage;
	vector<int> numberStorage;
	vector<string> stringStorage;

	// Commands
	map<string, VMCommandStruct> VMCommands
	{
		VMCommand("add", VMCommandStruct{ "add", &VirtualMachine::add }),
		VMCommand("print", VMCommandStruct{ "print", &VirtualMachine::print }),
		VMCommand("nstore", VMCommandStruct{ "nstore", &VirtualMachine::nstore }),
		VMCommand("sstore", VMCommandStruct{ "sstore", &VirtualMachine::sstore })
	};
};

