/*
Stores the instructions of a program in binary
and in assembly and outputs them when input an address
 */

#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__

#include <map>
#include <iostream>
#include <string>
#include "Utility.h"

using namespace std;

class InstructionMemory{
private:
	//store the assembly instruction
	map < int , string> instMemory;
	//store the binary instruction
	map < int , string> binInstMemory;

	//holds the inputted addresses for inst and bin
	 int instInput;
	 int binInput;

	 //the outputs for inst and bin
	string instOutput;
	string binOutput;
public:
	//create empty instruction memeory
	InstructionMemory(){}
	//create instruction memory from a map of binary and assembly instructions
	InstructionMemory(map < int , string> instructions, map< int , string> binInstructions);

	//get the aseemby instruction at the address
	string getInstruction(int  address);
	//get the binary instruction at the address
	string getBinaryInstruction(int  address);	

	//print all contents
	void printAll ();

	//print inst input and output
	void printInst();
	//pirnt bin input and output
	void printBin();

	//get inst/bin input and output
	int getInstInput(){return instInput;}
	int getBinInput(){return binInput;}
	string getInstOutput(){return instOutput;}
	string getBinOutput(){return binOutput;}
};

#endif