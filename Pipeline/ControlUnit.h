#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <string>
#include <map>

//holds the output of the control wires after decode
struct ControlWires{
	long  regDst;
	long  jump;
	long  branch;
	long  memRead;
	long  memToReg;
	long  ALUOp0;
	long  ALUOp1;
	long  memWrite;
	long  ALUSrc;
	long  regWrite;
};

class ControlUnit{
public:
	//initialize control unit
	ControlUnit();

	//handles decode stage
	ControlWires process(string opcode);
private:
	//holds output values for particular inputs
	map <string, ControlWires> outputMap;
};


#endif