/*
The Alu Control which outputs the alu controller based on two bits and funct code
 */

#include "ALUControl.h"
using namespace std;

/*
Constructor to initialize based on params
 */
ALUControl::ALUControl(string functcode, int  op1, int  op2){

	getALUControl(functcode, op1, op2);
}

//returns the control signal as well as saves input and output
string ALUControl::getALUControl(string functionCode, int  ALUOp1, int  ALUOp2){
	//save inputs
	input.op0 = ALUOp1;
	input.op1 = ALUOp2;
	input.funct = functionCode;

	//get the output based on two bits and funct code
	string output ="";
	if( ALUOp1 == 0 && ALUOp2 == 0){
		output = "010";
	}else 
	if( ALUOp1 == 0 && ALUOp2 == 1){
		output = "110";
	}else
	{
		if(functionCode == "100000"){
			output = "010";
		}else
		if(functionCode == "100010"){
			output = "110";
		}else
		if(functionCode == "100100"){
			output = "000";
		}else
		if(functionCode == "100101"){
			output = "001";
		}else
		if(functionCode == "101010"){
			output = "111";
		}
	}

	//set output
	this->output = output;
	//cout << output << endl;
	return output;
}

//print out everything
void ALUControl::print(){
	cout << "Input" << endl;
	cout << "FunctCode : 0x" << hex << Utility::bStoi(input.funct) << endl;
	cout << "In0 : 0x" << hex << input.op0 << endl;
	cout << "In1 : 0x" << hex << input.op1 << endl;
	cout << "Output : 0x" << hex << Utility::bStoi(output) << endl;
}
/*
int  main() {
	string input = "101010";
	int  op1 = 1;
	int  op2 = 0;
	ALUControl(input, op1, op2);

}
*/