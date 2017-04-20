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


using namespace std;

class Parser {

public:

	Parser();
	void parseConfig(string file);
	void parseProgram();
	map<string, string> parseMemory();
	map<string, string> parseRegister();

	string getConfig(string key);
	string getMem(long key);
	string getReg(long key);
	string getProg(long key);

	map<long , long > getRegMap();
	map<long , long > getMemMap();
	map<long , string> getProgMap();
	map<long , string> getBinProg();

	void convertMemory();
	void convertRegister();
	void convertProgram();

	string rInst(string inst);
	string jInst(string inst);
	string iInst(string inst);

	string toBinary(long num, string result);

private:
	map <string, string> config;
	map <long , long > mem; //convert to string long 
	map <long , long > regMem; //long long 
	map <long , string> prog; 
	map<long , string> binProg;

};

#endif