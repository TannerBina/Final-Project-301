#ifndef __SHIFTLEFTTWO_H__
#define __SHIFTLEFTTWO_H__

#include <iostream>
#include <string>

using namespace std;

/*
	This class takes as input a int value representing an
	immediate value in binary. It effectively shifts the bits
	of this binary value two the left, which happens to multiply
	the value by four.
*/

class ShiftLeftTwo
{

public:
	ShiftLeftTwo(){};
	//shifts the immediate left storing output and input into variables
	ShiftLeftTwo(int immediate);
	//returns the shift as well as storing.
	int performShiftLeft(int imm);

	//retrieves the input and outputs
	int getInput(){return input;}
	int getOutput(){return output;}

	//prints out the input and outputs of the shift left unit
	void print();

private:
	//holds theinputs and outputs.
	int input;
	int output;

};

#endif