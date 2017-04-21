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
#include <string.h>

using namespace std;

/*
This class takes in input files and parses the data. The parsed files
are then stored to be used by the other classes. The register files, \
memory files and program files are all parsed and stored.
*/
class Parser {

public:

	//default constructor
	Parser();

	//this method takes in a config file name and stores the data
	void parseConfig(string file);

	//this method takes in an assembly file and stores the data
	void parseProgram();

	//this method gets the config value at a given key
	string getConfig(string key);

	//this method returns the register map
	map<int , int > getRegMap();

	//this method returns the memory map
	map<int , int > getMemMap();

	//this method returns the map storing whole instructions
	map<int , string> getProgMap();

	//this method returns the map storing the binary string 
	//of the instructions
	map<int , string> getBinProg();

	//this method converts the memory data into appropriate data forms
	void convertMemory();

	//this method converts the register data into appropriate data forms
	void convertRegister();

	//this method converts the program data into appropriate data forms
	void convertProgram();


private:

	//this method parses the memory file and separates the strings
	map<string, string> parseMemory();

	//this method parses the register file and separates the strings
	map<string, string> parseRegister();

	//this method converts RTYPE insts to binary strings
	string rInst(string inst);

	//this method converts JTYPE insts to binary strings
	string jInst(string inst);

	//this method converts ITYPE insts to binary strings
	string iInst(string inst);

	//this method takes in an int, string, and num bits to convert to binary
	string toBinary(int num, string result, unsigned int bits);

	//this method takes an instruction and separates it by its data
	vector<string> tokenize(string insts);

	//maps to hold the parsed data
	map <string, string> config;
	map <int , int > mem; 
	map <int , int > regMem; 
	map <int , string> prog; 
	map<int , string> binProg;

};

#endif