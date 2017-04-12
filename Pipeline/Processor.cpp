#include "Parser.h"

int main(int argc, char const* argv[]) {

	Parser parser;
	parser.parseConfig(argv[1]);
	parser.convertMemory();
	parser.convertRegister();
	parser.parseProgram();

	cout << parser.getConfig("program_input") << endl;
	cout << parser.getConfig("memory_contents_input") << endl;
	cout << parser.getMem("10000030") << endl;
	cout << parser.getReg("14")<< endl;
	cout << parser.getMem("1000004c") << endl;
	cout << parser.getProg(4194308) << endl;

	
	return 0;

}