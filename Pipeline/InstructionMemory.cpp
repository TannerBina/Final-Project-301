#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(map <int , string> instructions, map <int , string> binInstructions){
	map<int , string>::iterator it;
	for (it = instructions.begin(); it != instructions.end(); it++){
		instMemory[it->first] = it->second;
	}
	for (it = binInstructions.begin(); it != binInstructions.end(); it++){
		binInstMemory[it->first] = it->second;
	}
}

string InstructionMemory::getInstruction(int  address){
	instInput = address;
	instOutput = instMemory[address];

	return instMemory[address];
}

string InstructionMemory::getBinaryInstruction(int  address){
	binInput = address;
	binOutput = binInstMemory[address];

	return binInstMemory[address];
}

void InstructionMemory::printAll (){
	map<int , string>::iterator it;
	cout << "Instruction Memory" << endl;
	for (it = binInstMemory.begin(); it != binInstMemory.end(); it++){
		cout << hex << it->first << " : " << hex << stoi(it->second, nullptr, 2) << endl;
	}
}

void InstructionMemory::printBin(){
	cout << "Input : 0x" << hex << binInput << endl;
	cout << "Output : 0x" << hex << binStoL(binOutput) << endl;
}

void InstructionMemory::printInst(){
	cout << "Input : 0x" << hex << instInput << endl;
	cout << "Output : " << instOutput << endl;
}