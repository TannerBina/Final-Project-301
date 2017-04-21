#include "ALU.h"

using namespace std;

//constructor to initialize with control and srces 
ALU::ALU(string control, int src1, int src2){

 	performALU(control, src1, src2);

}

//perform alu
LineInfo  ALU::performALU(string control, int src1, int src2){
	//save inputs
	input.control = control;
	input.in0 = src1;
	input.in1 = src2;

	//based on control do operation
	int out = 0;
	if(control == "010"){
		out = src1 + src2; // return the sum

	}
	else if(control == "110"){
		out= src1 - src2; // return the subtraction
	}
	else if(control == "000"){
		out = src1 & src2; //return the bitwise AND
	}
	else if(control == "001"){
		out = src1 | src2;// return the bitwise OR
	}
	else if(control == "111"){// return SLT, 
		if (src1 < src2){
			out = 1;
		}else{
			out = 0;
		}
	}

	//get the result store and output it
	LineInfo res;
	res.output = out;
	if (res.output == 0){
		res.zeroOrOne = 1;
	} else {
		res.zeroOrOne = 0;
	}

	this->output = res;
	return res;
}

//print out all input and oututs
void ALU::print(){
	cout << "Input" << endl;
	cout << "Control : 0x" << hex << Utility::bStoi(input.control) << endl;
	cout << "In0 : 0x" << hex << input.in0 << endl;
	cout << "In1 : 0x" << hex << input.in1 << endl;
	cout << "Output" << endl;
	cout << "Output : 0x" << hex << output.output << endl;
	cout << "Zero Line : 0x" << hex << output.zeroOrOne << endl;
}

