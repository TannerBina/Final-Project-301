#include "Parser.h"

int main() {
	Parser parser;
	parser.parseConfig("input.config");
	parser.convertMemory();
	parser.convertRegister();

	cout << parser.config["program_input"] << endl;
	cout << parser.mem["10000030"] << endl;
	cout << parser.regMem[20] << endl;

	return 0;

}