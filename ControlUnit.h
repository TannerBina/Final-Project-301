#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <string>
#include <map>

struct ControlWires{
	int regDst;
	int jump;
	int branch;
	int memRead;
	int memToReg;
	int ALUOp0;
	int ALUOp1;
	int memWrite;
	int ALUSrc;
	int regWrite;
};

class ControlUnit{
public:
	ControlUnit();

	ControlWires process(string opcode);
private:
	map <string, ControlWires> outputMap;
};


#endif