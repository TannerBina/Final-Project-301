#include "ShiftLeftTwo.h"
using namespace std;


ShiftLeftTwo::ShiftLeftTwo(int immediate)
{
	performShiftLeft(immediate);
}


/*
SHifts left by two by multiplying by 4.
 */
int ShiftLeftTwo::performShiftLeft(int imm)
{
	input = imm;
	output = imm * 4;
	return output;
}

/*
Prints ou the input and output of the unit.
 */
void ShiftLeftTwo::print(){
	cout << "Input : 0x" << hex << input << endl;
	cout << "Output : 0x" << hex << output << endl;
}