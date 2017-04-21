/*
Implementation of instruction memeory.
 */

#include "InstructionMemory.h"

/*
Constructor from map of instructions and binInstructions
 */
InstructionMemory::InstructionMemory(map <int , string> instructions, map <int , string> binInstructions){
	//copy maps with iterator for loops
	map<int , string>::iterator it;
	for (it = instructions.begin(); it != instructions.end(); it++){
		if (!(it->second).empty())
			instMemory[it->first] = it->second;
	}
	for (it = binInstructions.begin(); it != binInstructions.end(); it++){
		if (!(it->second).empty())
			binInstMemory[it->first] = it->second;
	}
}

//return instruction at address
string InstructionMemory::getInstruction(int  address){
	//set inst input and output
	instInput = address;
	instOutput = instMemory[address];

	//return instruction
	return instMemory[address];
}

//return binary at address
string InstructionMemory::getBinaryInstruction(int  address){
	//set bin input and output
	binInput = address;
	binOutput = binInstMemory[address];

	//return binary
	return binInstMemory[address];
}

//prints all values in the map
void InstructionMemory::printAll (){
	//go through map and print all instructions
	map<int , string>::iterator it;
	cout << "Instruction Memory" << endl;
	for (it = binInstMemory.begin(); it != binInstMemory.end(); it++){
		if (!(it->second).empty())
			cout << "0x" << hex << it->first << " : 0x" << hex << Utility::bStoi(it->second, false) << endl;
	}
}

//print in and out of binary
void InstructionMemory::printBin(){
	cout << "Input : 0x" << hex << binInput << endl;
	cout << "Output : 0x" << hex << Utility::bStoi(binOutput, false) << endl;
}

//print in and out of instruction
void InstructionMemory::printInst(){
	cout << "Input : 0x" << hex << instInput << endl;
	cout << "Output : " << instOutput << endl;
}