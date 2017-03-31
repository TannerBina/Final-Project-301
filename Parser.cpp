#include "Parser.h"


/*
This class reads in a file and parses it following all constraints
set forth by general syntax of input files
*/


Parser::Parser(string file){

ifstream fileParser;
open(file);

}

void Parser::parseConfig(string file) {

	Parser configParser = new Parser(file);
	if(fileParser.is_open()) {
		string line;

		while(getLine(fileParser, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int equalsPos = line.find('=');
			if(line.at(equalsPos - 1) == ' '){
				line.erase(equalsPos - 1, 1);
			}

			if(line.at(equalsPos + 1) == ' '){
				line.erase(equalsPos + 1, 1);
			}

			config[line.substr(0, equalsPos)] = line.substr(equalsPos + 1);

		}
	}
	fileParser.close();

}

void Parser::parseProgram(){
	string program = config[program_input];

	Parser programParser = new Parser(program);

	Instruction i;


}

void Parser::parseMemory() {

}

void Parser::parseRegister(){

}



