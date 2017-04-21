#include "Multiplexor.h"

using namespace std;

	Multiplexor::Multiplexor(MultiplexorInput in){
		process(in);
	}

//process an input returning output and storing input and output
	int Multiplexor::process(MultiplexorInput in){
		input = in;
		if (in.control == 0){
			output = in.in0;
			return in.in0;
		} else {
			output = in.in1;
			return in.in1;
		}
	}

	//print out input and output
	void Multiplexor::print(){
		cout << "Input" << endl;
		cout << "In0 : 0x" << hex << input.in0 << endl;
		cout << "In1 : 0x" << hex << input.in1 << endl;
		cout << "Control : 0x" << hex << input.control << endl;
		cout << "Output : 0x" << hex << output << endl;
	}