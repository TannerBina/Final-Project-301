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
#include "ALU.h"
#include "ShiftLeftTwo.h"
#include "SignExtend.h"
#include "Utility.h"
#include <iostream>
#include <string>

class Processor{
private:
	Parser parser;
	PC pc;
	InstructionMemory instMem;
	RegisterTable regFile;
	DataMemory dataMem;

	ALU pcAddALU;
	ALU mainALU;
	ALU branchALU;

	Multiplexor regMult;
	Multiplexor aluMult;
	Multiplexor writeBackMult;
	Multiplexor branchMult;
	Multiplexor jumpMult;
	
	ShiftLeftTwo jumpShift;
	ShiftLeftTwo branchShift;

	ControlUnit control;

	ALUControl aluControl;

	SignExtend signExtend;

	string output_mode;
	bool debug_mode;
	bool print_memory_contents;
	bool write_to_file;
	string output_file;
public:
	Processor();
	Processor(string initFile);

	bool getBool(string input);

	void step();
};

#endif