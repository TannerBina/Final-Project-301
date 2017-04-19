#ifndef __ALU_H__
#define __ALU_H__

#include <iostream>
#include <string>

/*
ALU - takes Three inputs outputs the result
-a control input: from ALUControl
-data input 1 long  from either signextend or register table
-data input 2 long  frome either signextend or register table
output the result of the operation(AND, OR, ADD, Subtract, SLT) performed on the inputs
and zero or one depending on the output
*/

using namespace std;

struct LineInfo{
	long  output;
	long  zeroOrOne;
};

class ALU{

public:

	ALU(){};
	ALU(string control, long  src1, long  src2);

	//given a control string taken from ALUcontrol, and registers,
	//performs the correct operation based on the ALU control
	//and returns long  with the selected action on the input
	long  performALU(string control, long  src1, long  src2);
	
};

#endif
