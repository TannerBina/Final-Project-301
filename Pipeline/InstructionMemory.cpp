#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(map <long , string> instructions, map <long , string> binInstructions){
	map<long , string>::iterator it;
	for (it = instructions.begin(); it != instructions.end(); it++){
		instMemory[it->first] = it->second;
	}
	for (it = binInstructions.begin(); it != binInstructions.end(); it++){
		binInstMemory[it->first] = it->second;
	}
}

string InstructionMemory::getInstruction(long  address){
	return instMemory[address];
}

string InstructionMemory::getBinaryInstruction(long  address){
	return binInstMemory[address];
}

void InstructionMemory::prlong (){
	map<long , string>::iterator it;
	cout << "Instruction Memory" << endl;
	for (it = binInstMemory.begin(); it != binInstMemory.end(); it++){
		cout << hex << it->first << " : " << hex << stoi(it->second, nullptr, 2) << endl;
	}
}