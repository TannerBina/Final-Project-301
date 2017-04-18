#include "Parser.h"
#include "Processor.h"

Processor::Processor()
:single_step(false), debug_mode(false), print_memory_contents(false),
write_to_file(false){

}

Processor::Processor(string initFile){
	//populate all the maps
	parser.parseConfig(initFile);
	parser.convertMemory();
	parser.convertRegister();
	parser.parseProgram();

	//get the config values
	output_mode = parser.getConfig("output_mode");
	debug_mode = getBool(parser.getConfig("debug_mode"));
	write_to_file = getBool(parser.getConfig("write_to_file"));
	output_file = parser.getConfig("output_file")

	if (debug_mode){
		cout << "Output Mode : " << output_mode << endl;
		cout << "Debug Mode : " << debug_mode << endl;
		cout << "Write to File : " << write_to_file << endl;
		cout << "Output file : " << output_file << endl;
	}

	regFile(parser.getRegMap());
	dataMem(parser.getMemMap());
	instMem(parser.getProgMap());

	if (debug_mode){
		cout << endl;
		regFile.print();
		cout << endl;
		dataMem.print();
		cout << endl;
		instMem.print();
		cout << endl;
	}
}

bool Processor::getBool(string input){
	if (input == "true") return true;
	return false;
}

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