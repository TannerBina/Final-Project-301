#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

class InstructionMemory{
private:
	map <int, string> instMemory;
	map <int, string> binInstMemory;
public:
	InstructionMemory(){}
	InstructionMemory(map <int, string> instructions, map<int, string> binInstructions);

	string getInstruction(int address);
	string getBinaryInstruction(int address);	

	void print();
};

#endif