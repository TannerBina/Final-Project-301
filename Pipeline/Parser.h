#ifndef __PARSER_H__
#define __PARSER_H__



#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cctype>
#include "Opcode.h"
#include <sstream>
#include <vector>
#include "Utility.h"


using namespace std;

class Parser {

public:

	Parser();
	void parseConfig(string file);
	void parseProgram();
	map<string, string> parseMemory();
	map<string, string> parseRegister();

	string getConfig(string key);
	string getMem(int key);
	string getReg(int key);
	string getProg(int key);

	map<int , int > getRegMap();
	map<int , int > getMemMap();
	map<int , string> getProgMap();
	map<int , string> getBinProg();

	void convertMemory();
	void convertRegister();
	void convertProgram();

	string rInst(string inst);
	string jInst(string inst);
	string iInst(string inst);

	string toBinary(int num, string result, unsigned int bits
		);

private:
	map <string, string> config;
	map <int , int > mem; //convert to string int 
	map <int , int > regMem; //int int 
	map <int , string> prog; 
	map<int , string> binProg;

};

#endif