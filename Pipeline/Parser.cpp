#include "Parser.h"


/*
This class reads in a file and parses it following all constraint s
set forth by general syntax of input files
*/

/*
Default constructor, creates blank object
*/
Parser::Parser(){

}

/*
This method parses the configuration file, storing the parameter and values
*/
void Parser::parseConfig(string file) {

	ifstream ifs;
	ifs.open(file.c_str());

	//checks if the file is open
	if(ifs.is_open()) {
		string line;

		//iterates through the file line by line
		while(getline(ifs, line)) {

			//does nothing if the lines starts with '#' or is empty
			if (line[0] == '#' || line.empty()) {
				continue;
			}

			int equalsPos = line.find('=');

			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			config[line.substr(0, equalsPos)] = line.substr(equalsPos + 1, line.size() - equalsPos - 2);

		}
	}

}

/*
This method takes in an assembly code file and stores it line by line according to its memory
*/
void Parser::parseProgram(){
	int key = 4194304;
	string program = config["program_input"];

	ifstream ifs(program.c_str());

	//checks if the input file is open
	if (ifs.is_open()){
		string line;

		//iterates through the file line by line
		while(getline(ifs, line)){
			

			//checks if the line is empty or a comment
			if (line[0] == '#' || line.empty()){
				continue;
			}

			prog[key] = line;
			key += 4;
		}
	}
	map<int, string>::iterator itr;
	string res;
	for (itr = prog.begin(); itr != prog.end(); itr++) {
		string asem = itr->second;
		stringstream s(asem);
		vector<string> insts;
		while(!s.eof()){
			string tmp;
			s >> tmp;
			insts.push_back(tmp);
		}
		for (vector<string>::iterator iter = insts.begin(); iter != insts.end(); iter++) {
			string tmp = *iter;
			res.append(tmp);
			res.append(" ");
		}
		prog[itr->first] = res;
		res = '\0';

	}
	
}

	

/*
This method takes in an int eger and a string, converting an int eger
to a binary string
*/
string Parser::toBinary(int num, string result, unsigned int bits){
	stringstream ss;
  stringstream bit;
  string temp;

  //makes sure the nuber is not zero and iterates
  while(num!=0) {

    temp = ss.str();
    ss.str("");

    //checks if the number is multiple of 2
    if (num%2 == 0) {

      ss << 0 << temp;

    //if not multiple of 2, adds 1 to the string
    } else {
      ss << 1 << temp;
    }
    num /= 2;
  }

  result = ss.str();

  //determines whether zeros need to be added to string
  if (result.length() < bits) {

    //iterates through number of 0s that need to be added
    for (unsigned int i = result.length(); i < bits; i++) {
      bit << 0;
    }
  }

  string bitnum = bit.str();
  bitnum += result;
  result = bitnum;
  return result;
}


/*
This method parses the memory file storing the memory addresses and value stored at them
*/
map<string, string> Parser::parseMemory() {
	
	string memory = config["memory_contents_input"];

	map<string, string> temp;

	ifstream ifs (memory.c_str());

	//checks if file is open
	if(ifs.is_open()) {
		string line;

		//iterates through the file line by line
		while(getline(ifs, line)) {

			//ignores lines starting with '#' or empty lines
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

/*
This method parses the register file and stores the register number and value 
*/
map<string, string> Parser::parseRegister(){

	string reg = config["register_file_input"];
	map <string, string> temp;
	ifstream ifs(reg.c_str());

	//checks if the file is open
	if(ifs.is_open()) {
		string line;

		//iterates through the file line by line
		while(getline(ifs, line)) {

			//if the line starts with '#' or is empty, do nothing
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

/*
This method takes the information from the memory file and makes all
the values uniformly formatted
*/
void Parser::convertMemory() {

	map <string, string> temp(parseMemory());
	map<string, string> copy;
	map<string, string>::iterator itr;

	//iterates through the map
	for(itr = temp.begin(); itr != temp.end(); ++itr) {
		string res = itr->first;
		string sec = itr->second;

		//checks if the value is preceded by 0x and erases if true
		if(sec[1] == 'x') {
			sec.erase(0,2);

			//iterates through the characters in the value
			for (int i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;

		} else {

			//iterates through the characters in the value
			for (int i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;
		}

	}


	//iterates through string map converting values to ints
	for (itr = copy.begin(); itr!= copy.end(); itr++){

		string res = itr->first;
		int key = hStoi(res);
		string val = itr->second;
		int value = hStoi(val);
		mem[key] = value;
	}

}

/*
This method takes the information from the register file and makes
all the values uniformly formatted
*/
void Parser::convertRegister(){
	map <string, string> temp = parseRegister();
	map<string, string> copy;
	map<string, string>::iterator itr;

	//iterates through the key value pairs of the map
	for(itr = temp.begin(); itr != temp.end(); ++itr) {
		string sec = itr->second;
		string res = itr->first;

		//checks if the value is preceded by 0x and deletes if true
		if(sec[1] == 'x') {
			string res = itr->first;
			sec.erase(0,2);

			//iterates through the characters in the value
			for (int i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
				sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;

		} else {

			//iterates through the characters in the value
			for (int i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(!(sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}

			copy[res] = sec;

			}
		
		}
	}

	//iterates through string map converting to ints
	for (itr = copy.begin(); itr!= copy.end(); itr++){
		
		string res = itr->first;
		int key = hStoi(res);
		string val = itr->second;
		int value = hStoi(val);
		regMem[key] = value;
	}
}

/*
This method converts the assembly code into binary strings by
the instruction type and then stores the string into
its map
*/
void Parser::convertProgram(){


	OpcodeTable opcodetab;
	string binStr;
	map<int, string>::iterator itr;
	map<int, string> copy = getProgMap();

	//iterates through the instructions from the input file
	for(itr = copy.begin(); itr!=copy.end(); itr++){
		char delim = ' ';
		string val = itr->second;

		string op = val.substr(0, val.find(delim));

		//checks if the instruction is RTYPE
		if(opcodetab.getInstType(op) == RTYPE){
			binStr += rInst(val);
		}

		//checks if the instruction is ITYPE
		if(opcodetab.getInstType(op) == ITYPE){
			binStr += iInst(val);
		}

		//checks if the instruction is JTYPE
		if(opcodetab.getInstType(op) == JTYPE){
			binStr += jInst(val);
		}

		binProg[itr->first] = binStr;
		
	}

}	

/*
This method takes an RTYPE instruction and converts it into a binary string
*/
string Parser::rInst(string inst){
	string res;
	string str;
	OpcodeTable opcodetab;
	char delim = ' ';
	string i = inst.substr(0, inst.find(delim));
	string op = opcodetab.getOpcode(op);
	str+=op;

	//checks if the instruction has an rs register
	if(opcodetab.RSposition(i) != -1){

	//if none, 0s are appended to the binary string
	} else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an rd register
	if(opcodetab.RDposition(i) != -1){

	//if none, 0s are appended to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an rt position
	if(opcodetab.RTposition(i) != -1){

	//if none, 0s are appended to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an immediate
	if (opcodetab.IMMposition(i) != -1){

	//if none, appends 0s to the binary string
	} else {
		res = toBinary(0, res, 5);
    	str+=res;
	}

	return str;

}

/*
This method takes an ITYPE instruction and converts it into a binary string
*/
string Parser::iInst(string inst){
	string res;
	string str;
	OpcodeTable opcodetab;
	char delim = ' ';
	string i = inst.substr(0, inst.find(delim));
	string op = opcodetab.getOpcode(op);
	str += op;

	//checks if the instruction has an rs position
	if(opcodetab.RSposition(i) != -1){

	//if none, appends 0s to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an rt position
	if(opcodetab.RTposition(i) != -1){
		
	//if none, appends 0s to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	if (opcodetab.IMMposition(i) != -1){

	//if none, appends 0s to the binary string
	} else {
		res = toBinary(0, res, 5);
    	str+=res;
	}

	return str;

}

/*
This method takes a JTYPE instruction and converts it into a binary string
*/
string Parser::jInst(string inst){
	string res;
	OpcodeTable opcodetab;
	char delim = ' ';
	string op = inst.substr(0, inst.find(delim));
	op = opcodetab.getOpcode(op);
	res += op;

	return res;

}

/*
This method gets the value of the configuration map at the 
string specified
*/
string Parser::getConfig(string key){
	return config[key];

}

/*
This method returns the map containing the register information
*/
map<int , int > Parser::getRegMap(){
	return regMem;

}

/*
This method returns the map containing the memory information
*/
map<int , int > Parser::getMemMap(){
	return mem;
}

/*
This method returns the map containing the program instruction information
*/
map<int , string> Parser::getProgMap(){
	return prog;
}

/*
This method returns the map containing the binary string associated
with an assembly instruction
*/
map<int , string> Parser::getBinProg(){
	return binProg;
}




	





