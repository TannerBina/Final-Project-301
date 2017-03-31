#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Instruction.h"


using namespace std;

class Parser {

public:

	Parser(string file);
	void parseConfig(string file);
	void parseProgram();
	void parseMemory();
	void parseRegister();

private:
	map <string, string> config;

};