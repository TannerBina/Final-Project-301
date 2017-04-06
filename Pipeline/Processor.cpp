#include "Parser.h"

int main(int argc, char const* argv[]) {

	Parser parser;
	string in = argv[1];
	parser.parseConfig(in);
	parser.convertMemory();
	parser.convertRegister();

	cout << parser.config["program_input"] << endl;
	cout << parser.mem["10000030"] << endl;
	cout << parser.regMem[20] << endl;

	cout << "hi" << endl;
	
	return 0;

}