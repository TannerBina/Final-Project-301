#ifndef __SIGNEXTEND_H__
#define __SIGNEXTEND_H__

#include <iostream>
#include <string>

using namespace std;

/*
	This class takes in as input the immediate field of an instruction,
	bits [15 - 0], and returns a 32-bit immediate. It fills in the bits
	[31 - 16] with the same value that bit [15] has.
*/

class SignExtend
{
public:
	SignExtend(){};
	SignExtend(int imm);
	int extendToThirtyTwo(int imm);

	void print();

	int getInput(){return input;}
	int getOutput(){return output;}

private:
	int input;
	int output;
};

#endif