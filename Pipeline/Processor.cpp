#include "Parser.h"

int main(int argc, char const* argv[]) {

	Parser parser;
	parser.parseConfig(argv[1]);
	parser.convertMemory();
	parser.convertRegister();

	cout << parser.config["program_input"] << endl;
	cout << parser.config["memory_contents_input"] << endl;
	cout << parser.mem["10000030"] << endl;
	cout << parser.regMem["20"] << endl;
	cout << parser.mem["1000006c"] << endl;

	
	return 0;

}