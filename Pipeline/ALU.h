#ifndef __ALU_H__
#define __ALU_H__

#include <iostream>
#include <string>
#include "Utility.h"

/*
ALU - takes Three inputs outputs the result
-a control input: from ALUControl
-data input 1 int  from either signextend or register table
-data input 2 int  frome either signextend or register table
output the result of the operation(AND, OR, ADD, Subtract, SLT) performed on the inputs
and zero or one depending on the output
*/

using namespace std;

//the output for the alu
struct LineInfo{
	int  output;
	int  zeroOrOne;
};

//the input for the alu
struct ALUInput{
	string control;
	int in0;
	int in1;
};

class ALU{

public:

	ALU(){};
	//takes in control src1 and src2 for initialize
	ALU(string control, int  src1, int  src2);

	//given a control string taken from ALUcontrol, and registers,
	//performs the correct operation based on the ALU control
	//and returns int  with the selected action on the input
	LineInfo  performALU(string control, int  src1, int  src2);

	//get input ad output
	LineInfo getOutput(){return output;}
	ALUInput getInput(){return input;}

	//print the input and outputs ut
	void print();

private:
	//store the input and outputs
	LineInfo output;
	ALUInput input;
};

#endif
