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
	//constructor for an immediate value.
	SignExtend(int imm);
	//extends an immediate value stores input and output into variables
	int extendToThirtyTwo(int imm);

	//prints out input and output data
	void print();

	//retrives input and outputs
	int getInput(){return input;}
	int getOutput(){return output;}

private:
	//holds input and output
	int input;
	int output;
};

#endif