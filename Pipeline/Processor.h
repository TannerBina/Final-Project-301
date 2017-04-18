#ifndef __Processor_H__
#define __Processor_H__

#include "Parser.h"
#include "PC.h"
#include "InstructionMemory.h"
#include "RegisterTable.h"
#include "DataMemory.h"
#include "Multiplexor.h"
#include "ControlUnit.h"
#include "ALUControl.h"
#include <iostream>

class Processor{
private:
	Parser parser;
	PC pc;
	InstructionMemory instMem;
	RegisterTable regFile;
	DataMemory dataMem;
	//TODO add necessary ALUs
	Multiplexor mult;
	//TODO add shift left 2 units
	ControlUnit control;
	ALUControl aluControl;
	//TODO add sign extend unit;
	
	string output_mode;
	bool debug_mode;
	bool print_memory_contents;
	bool write_to_file;
	string output_file;
public:
	Processor();
	Processor(string initFile);

	bool getBool(string input);

	int binStoI(string in);

	void step();
};

#endif