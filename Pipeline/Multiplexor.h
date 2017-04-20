#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

#include <iostream>

using namespace std;

struct MultiplexorInput{
	int in0;
	int in1;
	int control;
};

class Multiplexor{
public:
	Multiplexor(){}
	Multiplexor(MultiplexorInput in){
		process(in);
	}

	int process(MultiplexorInput in){
		input = in;
		if (in.control == 0){
			output = in.in0;
			return in.in0;
		} else {
			output = in.in1;
			return in.in1;
		}
	}

	void print(){
		cout << "Input" << endl;
		cout << "In0 : 0x" << hex << input.in0 << endl;
		cout << "In1 : 0x" << hex << input.in1 << endl;
		cout << "Control : 0x" << hex << input.control << endl;
		cout << "Output : 0x" << hex << output << endl;
	}

	MultiplexorInput getInput(){return input;}
	int getOutput(){return output;}

private:
	MultiplexorInput input;
	int output;

};

#endif