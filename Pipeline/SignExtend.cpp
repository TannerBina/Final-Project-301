#include "SignExtend.h"
using namespace std;

/*
	This method sign-extends the int value which 
	is taken as input according to the most significant bit.
*/
SignExtend::SignExtend(int immediate)
{
	extendToThirtyTwo(immediate);
}

/*
	This method takes in as input a int - which is 32 bits —
	and it keeps the same value in a int of 32 bits.
*/
int SignExtend::extendToThirtyTwo(int thisWillDoNothing)
{
	input = output = thisWillDoNothing;
	return thisWillDoNothing;
}

/*
Prints out the input and output data for the sign extend unit.
 */
void SignExtend::print(){
	cout << "Input : 0x" << hex << input << endl;
	cout << "Output : 0x" << hex << output << endl;
}

