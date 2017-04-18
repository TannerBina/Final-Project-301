#ifndef __REGISTERTABLE_H__
#define __REGISTERTABLE_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

//holds the input to the register table on each stage
struct RegInput{
	long readReg1;
	long readReg2;
	long writeReg;
	long regWrite;
};

//the output of the register at a stage
struct RegOutput{
	long readData1;
	long readData2;	
};

class RegisterTable{
public:
	//construct an empty initial register table
	RegisterTable(){}
	//construct a register table based on an initialization map
	RegisterTable(map<long , long > initMap);

	//process one input cycle to the register, outputting the read datas
	RegOutput process(RegInput in);
	//process the writeback cycle, true if written to register
	bool write(long writeData);

	void prlong ();
private:
	//stores register dat
	long registers[32];
	//holds whether registers are to be written to
	bool writeState;
	//register to write to in writeback stage
	long writeRegister;
};

#endif