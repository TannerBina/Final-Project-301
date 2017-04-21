#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <string>
#include <map>
#include <iostream>
#include "Utility.h"

//holds the output of the control wires after decode
struct ControlWires{
	int  regDst;
	int  jump;
	int  branch;
	int  memRead;
	int  memToReg;
	int  ALUOp0;
	int  ALUOp1;
	int  memWrite;
	int  ALUSrc;
	int  regWrite;
};

class ControlUnit{
public:
	//initialize control unit
	ControlUnit();

	//handles decode stage saving input opcode and output wires
	ControlWires process(string opcode);

	//gets the input and output
	string getInput(){return input;}
	ControlWires getOutput(){return output;}

	//print the input and output
	void print();
	
private:

	//store input and output
	string input;
	ControlWires output;

	//holds output values for particular inputs
	map <string, ControlWires> outputMap;
};


#endif