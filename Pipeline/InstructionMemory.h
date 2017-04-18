#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__

#include <map>

using namespace std;

class InstructionMemory{
private:
public:
	InstructionMemory(map <int, string> instructions)

	string getBinaryInstruction(int address);	

	void print();
};

#endif