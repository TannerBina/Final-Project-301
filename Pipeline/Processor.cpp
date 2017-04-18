#include "Parser.h"
#include "Processor.h"

/*Processor::Processor()
:single_step(false), debug_mode(false), print_memory_contents(false),
write_to_file(false){

}
*/

int main(int argc, char const* argv[]) {

	Parser parser;
	parser.parseConfig(argv[1]);
	parser.convertMemory();
	parser.convertRegister();
	parser.parseProgram();

	map<int, int> regist = parser.getRegMap();
	map<int, int> memory = parser.getMemMap();
	map<int, string> program = parser.getProgMap();

	cout << parser.getConfig("program_input") << endl;
	cout << parser.getConfig("memory_contents_input") << endl;
	cout << parser.getConfig("output_mode") << endl;
	cout << memory[268435520] << endl;
	cout << regist[14]<< endl;
	cout << memory[268435532] << endl;
	cout << program[4194308] << endl;

	
	return 0;

}