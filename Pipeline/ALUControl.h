#ifndef __ALUControl_H__
#define __ALUControl_H__

#include <iostream>
#include <string>
#include "Utility.h"
/*
What this class does, The ALU Control - takes in instruction funct field 
and ALUOp  and outputs the ALU control code

• ALU control: specifies what operation ALU performs 
– I.e., ALU operation control signals
– Eight input combinations (3 input control signals) 
– Five combinations used to select operation i.e this will return one of five functions
• Use truth table to determine how output will be generated based on the inputs

*/

using namespace std;

//the input to an alu cntrol
struct ALUControlInput{
	int op0;
	int op1;
	string funct;
};

class ALUControl{

private:
	//the function code and operators stored
	string functcode;
	int  op1, op2;

	//the output and input stored
	string output;
	ALUControlInput input;

public:
	ALUControl(){}
	//process the funct code and two operating bits, saving the values
	ALUControl(string functcode, int  op1, int  op2);
	string getALUControl(string functcode, int  op1, int  op2);

	//get the output and input
	string getOutput(){return output;}
	ALUControlInput getInput(){return input;}

	//print the output and the input
	void print();	
};

#endif
