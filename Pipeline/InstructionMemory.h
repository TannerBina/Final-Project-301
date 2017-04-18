#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

class InstructionMemory{
private:
	map <long , string> instMemory;
	map <long , string> binInstMemory;
public:
	InstructionMemory(){}
	InstructionMemory(map <long , string> instructions, map<long , string> binInstructions);

	string getInstruction(long  address);
	string getBinaryInstruction(long  address);	

	void prlong ();
};

#endif