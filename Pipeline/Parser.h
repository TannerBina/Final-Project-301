#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Instruction.h"
#include <algorithm>


using namespace std;

class Parser {

public:

	Parser();
	void parseConfig(string file);
	void parseProgram();
	map<string, string>parseMemory();
	map<string, string> parseRegister();

	string getConfig(string key);
	string getMem(string key);
	string getReg(int key);

	map<int, int> getRegMap();

	void convertMemory();
	void convertRegister();

	map <string, string> config;
	map <string, string> mem;
	map <string, string> regMem;


private:

};