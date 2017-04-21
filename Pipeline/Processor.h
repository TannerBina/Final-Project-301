/*
Simulates a 5 stage Computer Processor.
Given a configuration file, runs the program in it.
Outputs all control lines at each step, or writes to a file if
given one.
 */

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
	//the parser for the inputted files
	Parser parser;
	//holds the current address of the pc.
	PC pc;
	//holds all instructions in the inputted program to be ran.
	InstructionMemory instMem;
	//stores the registers and simulates a register file.
	RegisterTable regFile;
	//holds all data values in the simulation.
	DataMemory dataMem;

	//the alu used to increment the pc.
	ALU pcAddALU;
	//the main alu used for most operations.
	ALU mainALU;
	//the alu used for calculating the branch value.
	ALU branchALU;

	//multiplexor for the destination register of reg file
	Multiplexor regMult;
	//multiplexor for the input into the alu.
	Multiplexor aluMult;
	//multiplexor for the writeback to register data.
	Multiplexor writeBackMult;
	//multiplexor for the branch or pc to write to pc
	Multiplexor branchMult;
	//multiplexor for jump or pc or branch to write to pc.
	Multiplexor jumpMult;
	
	//the shift left for the jump value
	ShiftLeftTwo jumpShift;
	//the shift left for the branch value
	ShiftLeftTwo branchShift;

	//The main control unit for sending out control signals to all other units
	ControlUnit control;
	//takes in alu ops and function code and outputs alu code
	ALUControl aluControl;
	//does absolutely nothing
	SignExtend signExtend;

	//controls whether things are output in one large batch or in single steps
	string output_mode;
	//debug mode for additional debugging
	bool debug_mode;
	//print memory contents at the beginning of each instruction.
	bool print_memory_contents;
	//writes output to a file
	bool write_to_file;
	//the output file to be written to
	string output_file;
public:
	//empty base constructor
	Processor();
	//constructor off of an initialization file, then runs program.
	Processor(string initFile);

	//gets a boolean from an inputted string.
	bool getBool(string input);

	//waits for user input to continue if debugging or single step
	void step();
};

#endif