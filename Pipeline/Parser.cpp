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

			//checks if line contains a # and cuts off the comment
			if (line.find('#')){
				int pos = line.find('#');
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line = line.substr(0, pos - 1);
				cout << line << endl;
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

			//checks if the line contains a # and cuts off the comment
			if (line.find('#')){
				int pos = line.find('#');
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line = line.substr(0, pos - 1);
				cout << line << endl;
			}

			prog[key] = line;
			key += 4;
		}
	}

	map<int, string>::iterator itr;

	//iterates through the program map to remove unnecessary spaces
	for (itr = prog.begin(); itr != prog.end(); itr++) {

		string res;
		string asem = itr->second;
		stringstream s(asem);
		vector<string> insts;

		//makes sure the line has not ended and adds the values to a stream
		while(!s.eof()){

			string tmp;
			s >> tmp;
			insts.push_back(tmp);
		}

		//iterates through the new vector and adds the values back to the map
		for (vector<string>::iterator iter = insts.begin(); iter != insts.end(); iter++) {
			string tmp = *iter;
			res.append(tmp);
			res.append(" ");
		}

		prog[itr->first] = res;
		
	}
	
}

	

/*
This method takes in an integer and a string, converting an integer
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

			//checks if the line contains a # and cuts off the comment
			if (line.find('#')){
				int pos = line.find('#');
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line = line.substr(0, pos - 1);
				cout << line << endl;
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

			//checks if the lines contains a # and cuts off the comment
			if (line.find('#')){
				int pos = line.find('#');
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line = line.substr(0, pos - 1);
				cout << line << endl;
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
		int key = Utility::hStoi(res);
		string val = itr->second;
		int value = Utility::hStoi(val);
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
		int key = stoi(res, nullptr, 10);
		string val = itr->second;
		int value = Utility::hStoi(val);
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
	map<int, string>::iterator itr;
	map<int, string> copy = getProgMap();

	//iterates through the instructions from the input file
	for(itr = copy.begin(); itr!=copy.end(); itr++){
		string binStr;
		char delim = ' ';
		string val = itr->second;

		string op = val.substr(0, val.find(delim));

		//checks if the instruction is RTYPE
		if(opcodetab.getInstType(op) == 0){
			binStr = rInst(val);
		}

		//checks if the instruction is ITYPE
		if(opcodetab.getInstType(op) == 1){
			binStr = iInst(val);
		}

		//checks if the instruction is JTYPE
		if(opcodetab.getInstType(op) == 2){
			binStr = jInst(val);
		}

		//adds the bit strings to the map
		binProg[itr->first] = binStr;
		
	}

}	

/*
This method takes in an instruction in assembly and separates
it into its different parts, returning a vector containing
the different values.
*/
vector<string> Parser::tokenize(string inst){

	//sets up tokenizing the stiring instruction
	vector<string> instruct;
	char *cstr = new char[inst.length() + 1];
	strcpy(cstr, inst.c_str());
	char *tok;
	tok = strtok(cstr, " ,()");
	int num = strlen(tok);
	char* insts[num + 1];

	//adds strings of length 10 to the array
	for (int i = 0; i < num + 1; i++){
		insts[i]= new char[10];
	}
	int count = 0;

	//adds the tokens from the string to the vector
	while(tok != NULL){
		string s(tok);
		instruct.push_back(s);
		tok = strtok(NULL, " ,()");
	}
	
	return instruct;
} 

/*
This method takes an RTYPE instruction and converts it into a binary string
*/
string Parser::rInst(string inst){
	vector<string> instruct = tokenize(inst);

	//gets the opcode and name of the instruction
	string res;
	string str;
	OpcodeTable opcodetab;
	string name = instruct.at(0);
	string op = opcodetab.getOpcode(name);
	str+=op;

	//checks if the instruction has an rs register and gets
	//the binary encoding if so
	if(opcodetab.RSposition(name) != -1){

		int rs = opcodetab.RSposition(name);
		string regS = instruct.at(rs + 1);
		regS = regS.erase(0,1);
		int reg = stoi(regS, nullptr, 10);
		regS = toBinary(reg, regS, 5);
		str += regS;

	//if none, 0s are appended to the binary string
	} else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an rt position and gets the binary
	//encoding if so
	if(opcodetab.RTposition(name) != -1){

		int rt = opcodetab.RTposition(name);
		string regT = instruct.at(rt + 1);
		regT = regT.erase(0,1);
		int reg = stoi(regT, nullptr, 10);
		regT = toBinary(reg, regT, 5);
		str += regT;

	//if none, 0s are appended to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}
	//checks if the instruction has an rd register gets the binary
	//encoding if so
	if(opcodetab.RDposition(name) != -1){

		int rd = opcodetab.RDposition(name);
		string regD = instruct.at(rd + 1);
		regD = regD.erase(0,1);
		int reg = stoi(regD, nullptr, 10);
		regD = toBinary(reg, regD, 5);
		str += regD;

	//if none, 0s are appended to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	int immediate;

	//checks if the instruction has an immediate gets the binary
	//encoding if so
	if (opcodetab.IMMposition(name) != -1){
		int imm = opcodetab.IMMposition(name);
		string immed = instruct.at(imm + 1);

		//checks if the hex value is prepended by 0x and
		//converts to int
		if (immed[1] == 'x'){
			immed = immed.erase(0,2);
			immediate = Utility::hStoi(immed);

		//otherwise converts the decimal string to int	
		} else {
			immediate = stoi(immed, nullptr, 10);

		}
		immed = toBinary(immediate, immed, 5);
		str += immed;

	//if none, appends 0s to the binary string
	} else {
		res = toBinary(0, res, 5);
    	str+=res;
	}

	string funct = opcodetab.getFunctField(name);
  	str += funct;

	return str;

}

/*
This method takes an ITYPE instruction and converts it into a binary string
*/
string Parser::iInst(string inst){
	vector<string> instruct = tokenize(inst);

	//gets the name and opcode of the instruction
	string res;
	string str;
	OpcodeTable opcodetab;
	string name = instruct.at(0);
	string op = opcodetab.getOpcode(name);
	str += op;

	//checks if the instruction has an rs position
	if(opcodetab.RSposition(name) != -1){

		int rs = opcodetab.RSposition(name);
		string regS = instruct.at(rs + 1);
		regS = regS.erase(0,1);
		int reg = stoi(regS, nullptr, 10);
		regS = toBinary(reg, regS, 5);
		str += regS;

	//if none, appends 0s to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	//checks if the instruction has an rt position gets the binary
	//encoding if so
	if(opcodetab.RTposition(name) != -1){
		int rt = opcodetab.RTposition(name);
		string regT = instruct.at(rt + 1);
		regT = regT.erase(0,1);
		int reg = stoi(regT, nullptr, 10);
		regT = toBinary(reg, regT, 5);
		str += regT;
		
	//if none, appends 0s to the binary string
	}  else {
	    res = toBinary(0, res, 5);
	    str+=res;
	}

	int immediate;

	//checks if the instruction has an immediate and gets
	//the binary encoding if yes
	if (opcodetab.IMMposition(name) != -1){
		int imm = opcodetab.IMMposition(name);
		string immed = instruct.at(imm + 1);

		//checks if the immediate is a hex value prepended
		//by 0x and converts to integer
		if (immed[1] == 'x'){
			immed = immed.erase(0,2);
			immediate = Utility::hStoi(immed);

		//otherwise converts decimal string to integer	
		} else {
			immediate = stoi(immed, nullptr, 10);
		}

		immed = toBinary(immediate, immed, 16);
		str += immed;

	//if none, appends 0s to the binary string
	} else {
		res = toBinary(0, res, 16);
    	str+=res;
	}

	return str;
}

/*
This method takes a JTYPE instruction and converts it into a binary string
*/
string Parser::jInst(string inst){
	vector<string> instruct = tokenize(inst);

	//gets the name and opcode for the string
	string res;
	OpcodeTable opcodetab;
	string op = opcodetab.getOpcode(instruct.at(0));
	res += op;

	string immed = instruct.at(1);

	//checks if the immediate is a hex value prepended by 0x
	if (immed[1] == 'x') {
		immed = immed.erase(0,2);
	}

	//converts hex to integer and then binary
	int imm = stoi(immed, nullptr, 16);
	res += toBinary(imm / 4, res, 26);

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




	





