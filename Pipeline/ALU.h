#ifndef __ALU_H__
#define __ALU_H__

#include <iostream>
#include <string>

/*
ALU - takes Three inputs outputs the result
-a control input: from ALUControl
-data input 1 int from either signextend or register table
-data input 2 int frome either signextend or register table
output the result of the operation(AND, OR, ADD, Subtract, SLT) performed on the inputs
*/

using namespace std;

class ALU{

private:
	int result;

public:

	ALU();

	ALU(string control, int reg1, int reg2);

	//given a control string taken from ALUcontrol, and registers,
	//performs the correct operation based on the ALU control
	//and returns int with the selected action on the input
	int performALU(string control, int reg1, int reg2);
	
};

#endif
