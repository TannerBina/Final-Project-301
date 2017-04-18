#include "ALU.h"

using namespace std;

ALU::ALU(string control, long src1, long src2){

 	performALU(control, src1, src2);

}

LineInfo  ALU::performALU(string control, long src1, long src2){
	long out;
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

	LineInfo res;
	res.output = out;
	if (res.output == 0){
		res.zeroOrOne = 1;
	} else {
		res.zeroOrOne = 0;
	}

	return res;
}

