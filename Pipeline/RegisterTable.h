/*
Simulates a Register File.
Holds data in 32 registers.
 */

#ifndef __REGISTERTABLE_H__
#define __REGISTERTABLE_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

//holds the input to the register table on each stage
struct RegInput{
	int readReg1;
	int readReg2;
	int writeReg;
	int regWrite;
};

//the output of the register at a stage
struct RegOutput{
	int readData1;
	int readData2;	
};

class RegisterTable{
public:
	//construct an empty initial register table
	RegisterTable(){}
	//construct a register table based on an initialization map
	RegisterTable(map<int , int > initMap);

	//process one input cycle to the register, outputting the read datas
	RegOutput process(RegInput in);
	//process the writeback cycle, true if written to register
	bool write(int writeData);

	//retrieves the input and output
	RegInput getInput(){return input;}
	RegOutput getOutput(){return output;}
	//retrives the input when writing is attempted
	int getWriteInput(){return writeInput;}

	//print input and output
	void print();
	//print input from a write
	void printWrite();

	//print all registers and all values.
	void printAll ();
private:
	//stores register dat
	int registers[32];
	//holds whether registers are to be written to
	bool writeState;
	//register to write to in writeback stage
	int writeRegister;

	//stores the specified inputs and outputs.
	RegInput input;
	RegOutput output;
	int writeInput;
};

#endif