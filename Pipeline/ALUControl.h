#ifndef __ALUControl_H__
#define __ALUControl_H__

#include <iostream>
#include <string>
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

struct ALUControlInput{
	int op0;
	int op1;
	string funct;
};

class ALUControl{

private:
	string functcode;
	int  op1, op2;

	string output;
	ALUControlInput input;

public:
	ALUControl(){}
	ALUControl(string functcode, int  op1, int  op2);
	string getALUControl(string functcode, int  op1, int  op2);

	string getOutput(){return output;}
	ALUControlInput getInput(){return input;}

	void print();	

	int binStoL(string in){
	return stol(in, nullptr, 2);
}
};

#endif
