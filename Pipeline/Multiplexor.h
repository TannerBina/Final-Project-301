/*
A multiplexor which outputs one of the two inputs
based on a control wire inputted
 */

#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

#include <iostream>

using namespace std;

//the input for a multiplexor unit
struct MultiplexorInput{
	int in0;
	int in1;
	int control;
};

class Multiplexor{
public:
	Multiplexor(){}
	//create a multiplexor with the input
	Multiplexor(MultiplexorInput in){
		process(in);
	}

	//process an input returning output and storing input and output
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

	//print out input and output
	void print(){
		cout << "Input" << endl;
		cout << "In0 : 0x" << hex << input.in0 << endl;
		cout << "In1 : 0x" << hex << input.in1 << endl;
		cout << "Control : 0x" << hex << input.control << endl;
		cout << "Output : 0x" << hex << output << endl;
	}

	//get the input and output of the multiplexor
	MultiplexorInput getInput(){return input;}
	int getOutput(){return output;}

private:
	MultiplexorInput input;
	int output;

};

#endif