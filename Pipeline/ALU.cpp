#include "ALU.h"

using namespace std;

ALU::ALU(string control, int src1, int src2){

	performALU(control, src1, src2);
}

int ALU:performALU(string control, int  src1, int src2){

	int output;
	if(control == "010"){
		output = src1 + src2; // return the sum

	}
	else if(control == "110"){
		output = src1 - src2; // return the subtraction
	}
	else if(control == "000"){
		output = src1 & src2; //return the bitwise AND
	}
	else if(control == "001"){
		output = src1 | src2;// return the bitwise OR
	}
	else if(control == "111"){// return SLT, 
		if (src1 < src2){
			output = 1;
		}else{
			output = 0;
		}
		// might change depending on if Src2 is signed unsigned?
	}

}
