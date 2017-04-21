/*
Implements the control unit
 */

#include "ControlUnit.h"

using namespace std;

//creates a control unit table to return the correct control wires upon input of opcode.
ControlUnit::ControlUnit(){
	ControlWires rFormat; rFormat.regDst = 1; rFormat.ALUSrc = 0; rFormat.memToReg = 0; rFormat.regWrite = 1; rFormat.memRead = 0; rFormat.memWrite = 0; rFormat.branch = 0; rFormat.ALUOp1 = 1; rFormat.ALUOp0 = 0; rFormat.jump = 0;
	outputMap["000000"] = rFormat;
	ControlWires lw; lw.regDst = 0; lw.ALUSrc = 1; lw.memToReg = 1; lw.regWrite = 1; lw.memRead = 1; lw.memWrite = 0; lw.branch = 0; lw.ALUOp1 = 0; lw.ALUOp0 = 0; lw.jump = 0;
	outputMap["100011"] = lw;
	ControlWires sw; sw.regDst = 0; sw.ALUSrc = 1; sw.memToReg = 0; sw.regWrite = 0; sw.memRead = 0; sw.memWrite = 1; sw.branch = 0; sw.ALUOp1 = 0; sw.ALUOp0 = 0; sw.jump = 0;
	outputMap["101011"] = sw;
	ControlWires beq; beq.regDst = 0; beq.ALUSrc = 0; beq.memToReg = 0; beq.regWrite = 0; beq.memRead = 0; beq.memWrite = 0; beq.branch = 1; beq.ALUOp1 = 0; beq.ALUOp0 = 1; beq.jump = 0;
	outputMap["000100"] = beq;
	ControlWires addi; addi.regDst = 0; addi.ALUSrc = 1; addi.memToReg = 0; addi.regWrite = 1; addi.memRead = 0; addi.memWrite = 0; addi.branch = 0; addi.ALUOp1 = 0; addi.ALUOp0 = 0; addi.jump = 0;
	outputMap["001000"] = addi;
	ControlWires j; j.regDst = 0; j.ALUSrc = 0; j.memToReg = 0; j.regWrite = 0; j.memRead = 0; j.memWrite = 0; j.branch = 0; j.ALUOp1 = 0; j.ALUOp0 = 0; j.jump = 1;
	outputMap["000010"] = j;
}

/*
Process an opcode input
 */
ControlWires ControlUnit::process(string opcode){
	//save input and output
	input = opcode;
	output= outputMap[opcode];
	//return control wires from table
	return outputMap[opcode];
}

//print input and all outputs
void ControlUnit::print(){
	cout << "Input : 0x" << hex << Utility::bStoi(input, false) << endl;
	cout << "Output" << endl;
	cout << "RegDst : 0x" << hex << output.regDst << endl;
	cout << "Jump : 0x" << hex << output.jump << endl;
	cout << "Branch : 0x" << hex << output.branch << endl;
	cout << "MemRead : 0x" << hex << output.memRead << endl;
	cout << "MemToReg : 0x" << hex << output.memToReg << endl;
	cout << "ALUOp0 : 0x" << hex << output.ALUOp0 << endl;
	cout << "ALUOP1 : 0x" << hex << output.ALUOp1 << endl;
	cout << "MemWrite : 0x" << hex << output.memWrite << endl;
	cout << "ALUSrc : 0x" << hex << output.ALUSrc << endl;
	cout << "RegWrite : 0x" << hex << output.regWrite << endl;
}