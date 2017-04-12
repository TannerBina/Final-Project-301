#include "Parser.h"
#include "Processor.h"

Processor::Processor()
:single_step(false), debug_mode(false), print_memory_contents(false),
write_to_file(false){

}

int main(int argc, char const* argv[]) {

	Parser parser;
	parser.parseConfig(argv[1]);
	parser.convertMemory();
	parser.convertRegister();

	cout << parser.getConfig("program_input") << endl;
	cout << parser.getConfig("memory_contents_input") << endl;
	cout << parser.getMem("10000030") << endl;
	cout << parser.getReg("14")<< endl;
	cout << parser.getMem("1000004c") << endl;

	
	return 0;

}