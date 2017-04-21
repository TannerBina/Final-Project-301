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
	Multiplexor(MultiplexorInput in);

	//process an input returning output and storing input and output
	int process(MultiplexorInput in);

	//print out input and output
	void print();

	//get the input and output of the multiplexor
	MultiplexorInput getInput(){return input;}
	int getOutput(){return output;}

private:
	MultiplexorInput input;
	int output;

};

#endif