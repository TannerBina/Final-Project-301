#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Instruction.h"
#include <algorithm>


using namespace std;

class Parser {

public:

	Parser(string file);
	void parseConfig(string file);
	void parseProgram();
	map<string, string> parseMemory();
	map<int, string> parseRegister();

	string getConfig(string key);
	string getMem(string key);
	string getReg(int key);

	map<int, int> getRegMap();

	void convertMemory();
	void convertRegister();


private:
	map <string, string> config;
	map <string, int> mem;
	map <int, int> regMem;

};