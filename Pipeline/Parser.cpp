#include "Parser.h"


/*
This class reads in a file and parses it following all constraints
set forth by general syntax of input files
*/


Parser::Parser(){

}

void Parser::parseConfig(string file) {

	ifstream ifs;
	ifs.open(file.c_str());
	if(ifs.is_open()) {
		string line;

		while(getline(ifs, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int equalsPos = line.find('=');
			line.erase(remove(line.begin(), line.end(), ' '));

			config[line.substr(0, equalsPos)] = line.substr(equalsPos + 1);

		}
	}

}

void Parser::parseProgram(){
	string program = config["program_input"];

	Instruction i;

	//rs, rd, rt #s
	//opcode in binary
	//



}

map<string, string> Parser::parseMemory() {
	
	string memory = config["memory_content_input"];

	map<string, string> temp;
	ifstream ifs;
	ifs.open(memory.c_str());
	if(ifs.is_open()) {
		string line;

		while(getline(ifs, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int colonPos = line.find(':');
			line.erase(remove(line.begin(), line.end(), ' '));

			temp[line.substr(0, colonPos)] = line.substr(colonPos + 1);

		}
	}
	return temp;

}

map<int, string> Parser::parseRegister(){

	string reg = config["register_file_input"];
	map <int, string> temp;
	ifstream ifs;
	ifs.open(reg.c_str());
	if(ifs.is_open()) {
		string line;

		while(getline(ifs, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int colonPos = line.find(':');
			line.erase(remove(line.begin(), line.end(), ' '));
			string sub = line.substr(0, colonPos);
			int regNum = atoi(sub.c_str());

			temp[regNum] = line.substr(colonPos + 1);

		}
	}
	return temp;


}

void Parser::convertMemory() {

	map <string, string> temp = parseMemory();
	map<string, string>::iterator itr;


	for(itr = temp.begin(); itr != temp.end(); itr++) {
		if(itr->second[1] == 'x') {
			string res = itr->second;
			res.erase(0,2);
			mem[itr->first] = res;
		} else {
			mem[itr->first] = itr->second;
		}
	}
	//nothing preceded by 0x
	//second value as an decimal

}

void Parser::convertRegister(){
	map <int, string> temp = parseRegister();
	map<int, string>::iterator itr;

	for (int i = 0; i < 32; i++) {

		if(temp[i].at(1) == 'x') {
			string res = temp[i].erase(0,2);
			regMem[i] = res;
		} else {
			regMem[i] = temp[i];
		}
	}

}
	
	//second value decimal




