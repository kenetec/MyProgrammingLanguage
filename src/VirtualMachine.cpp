#include "VirtualMachine.h"


VirtualMachine::VirtualMachine(string filename)
{
	filestream = ifstream();
	filestream.open(filename);

	if (filestream.is_open()) {
		Read();
	}
	else {
		cerr << "Failed to open " + filename << endl;
	}
}

void VirtualMachine::Read()
{
	/*char* line;
	
	// Max line would be 256 characters to be safe.
	while (filestream.getline(line, 256, '\n'))
	{
		
	}*/

	vector<string> lines;
	string str;
	while (!filestream.eof())
	{
		char c = filestream.get();
		if (c != '\n')
			str += c;
		else
		{
			lines.push_back(str);
			str = "";
		}
	}

	for (int i = 0; i < lines.size(); i++) {
		string line = lines[i];
		string command;
		vector<string> args;
		string returnIndex;

		bool inParams = false;
		bool inReturn = false;
		bool inArgString = false;

		string argStr;
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			char character = *it;

			if (inReturn) {
				if (isdigit(character))
					returnIndex += character;
			}
			else if (inParams) {
				if (character != ')' && character != ',' && character != '[') {
					if (inArgString)
					{
						argStr += character;
					}
					else
					{
						inArgString = true;
						argStr = character;
					}
				}
				else if ((character == ',' && inArgString) || character == ')' && inArgString)
				{
					args.push_back(argStr);
					inArgString = false;
				}
				else if (character == '[')
					inReturn = true;
			}
			else if (character != '(')
			{
				command += character;
			}
			else inParams = true;
		}

		if (command != "") {
			// Execute
			(this->*(VMCommands[command]).func)(args, atoi(returnIndex.c_str()));
		}
	}
}

/*int VirtualMachine::ToDigit(char c)
{
	switch (c) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}*/

/*
COMMANDS START
*/
// nstore(data)[@]
void VirtualMachine::nstore(vector<string> args, StorageIndex returnIndex)
{
	int data = atoi(args[0].c_str());
	int dataIndex = numberStorage.size();
	// make entry in storage
	storage.push_back(StorageEntry{
		returnIndex,
		"number",
		dataIndex
	});

	numberStorage.push_back(data);
}

void VirtualMachine::sstore(vector<string> args, StorageIndex returnIndex)
{
	string data = args[0];
	int dataIndex = stringStorage.size();
	// make entry in storage
	storage.push_back(StorageEntry{
		returnIndex,
		"string",
		dataIndex
	});

	stringStorage.push_back(data);
}

void VirtualMachine::add(vector<string> args, StorageIndex returnIndex)
{
	int index1 = atoi(args[0].c_str());
	int index2 = atoi(args[1].c_str());
	int A = numberStorage[storage[index1].dataIndex];
	int B = numberStorage[storage[index2].dataIndex];

	int result = A + B;
	int dataIndex = numberStorage.size();

	// make entry in storage
	storage.push_back(StorageEntry{
		returnIndex,
		"number",
		dataIndex
	});

	numberStorage.push_back(result);
}

void VirtualMachine::print(vector<string> args, StorageIndex returnIndex)
{
	StorageEntry entry = storage[atoi(args[0].c_str())];
	
	if (entry.datatype == "number") {
		int data = numberStorage[entry.dataIndex];
		cout << data << endl;
	}
	else if (entry.datatype == "string") {
		string data = stringStorage[entry.dataIndex];
		cout << data << endl;
	}
}
/*
COMMANDS END
*/

VirtualMachine::~VirtualMachine()
{
	filestream.close();
}
