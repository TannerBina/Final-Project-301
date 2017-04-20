#include "ShiftLeftTwo.h"
using namespace std;


ShiftLeftTwo::ShiftLeftTwo(int immediate)
{
	performShiftLeft(immediate);
}


int ShiftLeftTwo::performShiftLeft(int imm)
{
	input = imm;
	output = imm * 4;
	return output;
}

void ShiftLeftTwo::print(){
	cout << "Input : 0x" << hex << input << endl;
	cout << "Output : 0x" << hex << output << endl;
}