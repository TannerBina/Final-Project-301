#include "Parser.h"


/*
This class reads in a file and parses it following all constralong s
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

			long equalsPos = line.find('=');

			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			config[line.substr(0, equalsPos)] = line.substr(equalsPos + 1, line.size() - equalsPos - 2);

		}
	}

}

/*
This method takes in an assembly code file and stores it line by line according to its memory
*/
void Parser::parseProgram(){
	long key = 4194304;
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
}

	

/*
This method takes in an long eger and a string, converting an long eger
to a binary string
*/
string Parser::toBinary(long num, string result){
	stringstream ss;
  	long rem;
  	if (num<=1)
  	{
    	ss << num;
    	result = ss.str();
  	} else
  	{
    	rem = num%2;
    	toBinary(num/2, result);
    	ss << rem;
    	result = result + ss.str();
  	}
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

			long colonPos = line.find(':');
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

			long colonPos = line.find(':');
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
			for (long i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;

		} else {

			//iterates through the characters in the value
			for (long i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;
		}

	}


	for (itr = copy.begin(); itr!= copy.end(); itr++){
		string res = itr->first;
		long key = stoi(res, nullptr, 16);
		string val = itr->second;
		cout << val << endl;
		long value = stoi(val, nullptr, 16);
		cout << value << endl;
		mem[key] = value;
	}
	//nothing preceded by 0x
	//second value as an decimal
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
			for (long i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(! (sec[i] >= '0' && sec[i] <= '9')){
				sec[i] = tolower(sec[i]);
				}
			}
			copy[res] = sec;

		} else {

			//iterates through the characters in the value
			for (long i = 0; i < sec.size(); i++) {

				//checks if the character is a letter, and makes it lowercase
				if(!(sec[i] >= '0' && sec[i] <= '9')){
					sec[i] = tolower(sec[i]);
				}

			copy[res] = sec;

			}
		
		}
	}

	for (itr = copy.begin(); itr!= copy.end(); itr++){
		string res = itr->first;
		long key = stoi(res);
		string val = itr->second;
		long value = stoi(val, nullptr, 16);
		regMem[key] = value;
	}
}

/*
This method converts the assembly code long o binary strings
*/
void Parser::convertProgram(){

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
map<long , long > Parser::getRegMap(){
	return regMem;

}

/*
This method returns the map containing the memory information
*/
map<long , long > Parser::getMemMap(){
	return mem;
}

/*
This method returns the map containing the program instruction information
*/
map<long , string> Parser::getProgMap(){
	return prog;
}

map<long , string> Parser::getBinProg(){
	return binProg;
}




	





