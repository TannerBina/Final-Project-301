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
	ShiftLeftTwo(int immediate);
	int performShiftLeft(int imm);

	int getInput(){return input;}
	int getOutput(){return output;}

	void print();

private:
	int input;
	int output;

};

#endif