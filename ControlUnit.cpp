#include "ControlUnit.h"

using namespace std;

ControlUnit::ControlUnit(){
	ControlWires rFormat; rFormat.regDst = 1; rFormat.ALUSrc = 0; rFormat.memToReg = 0; rFormat.regWrite = 1; rFormat.memRead = 0; rFormat.memWrite = 0; rFormat.branch = 0; rFormat.ALUOp1 = 1; rFormat.ALUOp0 = 0; rFormat.jump = 0;
	outputMap["000000"] = rFormat;
	ControlWires lw; lw.regDst = 0; lw.ALUSrc = 1; lw.memToReg = 1; lw.regWrite = 1; lw.memRead = 1; lw.memWrite = 0; lw.branch = 0; lw.ALUOp1 = 0; lw.ALUOp0 = 0; lw.jump = 0;
	outputMap["100011"] = lw;
	ControlWires sw; sw.regDst = -1; sw.ALUSrc = 1; sw.memToReg = -1; sw.regWrite = 0; sw.memRead = 0; sw.memWrite = 1; sw.branch = 0; sw.ALUOp1 = 0; sw.ALUOp0 = 0; sw.jump = 0;
	outputMap["101011"] = sw;
	ControlWires beq; beq.regDst = -1; beq.ALUSrc = 0; beq.memToReg = -1; beq.regWrite = 0; beq.memRead = 0; beq.memWrite = 0; beq.branch = 1; beq.ALUOp1 = 0; beq.ALUOp0 = 1; beq.jump = 0;
	outputMap["000100"] = beq;
	ControlWires addi; addi.regDst = -1; addi.ALUSrc = 1; addi.memToReg = 0; addi.regWrite = 1; addi.memRead = 0; addi.memWrite = 0; addi.branch = 0; addi.ALUOp1 = 0; addi.ALUOp0 = 0; addi.jump = 0;
	outputMap["001000"] = addi;
	ControlWires j; j.regDst = -1; j.ALUSrc = -1; j.memToReg = -1; j.regWrite = 0; j.memRead = 0; j.memWrite = 0; j.branch = -1; j.ALUOp1 = -1; j.ALUOp0 = -1; j.jump = 1;
	outputMap["000010"] = j;
}

ControlWires ControlUnit::process(string opcode){
	return outputMap[opcode];
}