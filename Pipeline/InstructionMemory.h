#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

class InstructionMemory{
private:
	map < int , string> instMemory;
	map < int , string> binInstMemory;

	 int instInput;
	 int binInput;

	string instOutput;
	string binOutput;
public:
	InstructionMemory(){}
	InstructionMemory(map < int , string> instructions, map< int , string> binInstructions);

	string getInstruction(int  address);
	string getBinaryInstruction(int  address);	

	void printAll ();

	void printInst();
	void printBin();

	int getInstInput(){return instInput;}
	int getBinInput(){return binInput;}
	string getInstOutput(){return instOutput;}
	string getBinOutput(){return binOutput;}

	int binStoL(string in){
		return stol(in, nullptr, 2);
	}
};

#endif