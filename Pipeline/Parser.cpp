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
			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			config[line.substr(0, equalsPos)] = line.substr(equalsPos + 1, line.size() - equalsPos - 2);

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
	
	string memory = config["memory_contents_input"];

	map<string, string> temp;
	ifstream ifs (memory.c_str());
	if(ifs.is_open()) {
		string line;
		while(getline(ifs, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int colonPos = line.find(':');
			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			temp[line.substr(0, colonPos)] = line.substr(colonPos + 1, line.size() - colonPos - 2);

		}
		
	}
	return temp;
	

}

map<string, string> Parser::parseRegister(){

	string reg = config["register_file_input"];
	map <string, string> temp;
	ifstream ifs;
	ifs.open(reg.c_str());
	if(ifs.is_open()) {
		string line;

		while(getline(ifs, line)) {

			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int colonPos = line.find(':');
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			string sub = line.substr(0, colonPos);

			temp[sub] = line.substr(colonPos + 1, line.size() - colonPos - 2);

		}
	}
	return temp;


}

void Parser::convertMemory() {

	map <string, string> temp(parseMemory());
	map<string, string>::iterator itr;

	for(itr = temp.begin(); itr != temp.end(); ++itr) {
		string res = itr->first;
		string sec = itr->second;
		if(sec[1] == 'x') {
			sec.erase(0,2);
			mem[res] = sec;
		} else {
			mem[res] = sec;
		}

	}
	//nothing preceded by 0x
	//second value as an decimal

}

void Parser::convertRegister(){
	map <string, string> temp = parseRegister();
	map<string, string>::iterator itr;

	for(itr = temp.begin(); itr != temp.end(); ++itr) {
		string sec = itr->second;
		string res = itr->first;
		if(sec[1] == 'x') {
			string res = itr->first;
			sec.erase(0,2);
			regMem[res] = sec;
		} else {
			regMem[res] = sec;
		}
	}
}
	
	//second value decimal




