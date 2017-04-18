#include "Processor.h"

<<<<<<< HEAD
using namespace std;


Processor::Processor()
:single_step(false), debug_mode(false), prlong _memory_contents(false), write_to_file(false){

}


Processor::Processor(string initFile){
	//populate all the maps
	parser.parseConfig(initFile);
	parser.convertMemory();
	parser.convertRegister();
	parser.parseProgram();
	parser.convertProgram();

	//get the config values
	output_mode = parser.getConfig("output_mode");
	debug_mode = getBool(parser.getConfig("debug_mode"));
	write_to_file = getBool(parser.getConfig("write_to_file"));
	prlong _memory_contents = getBool(parser.getConfig("prlong _memory_contents"));
	output_file = parser.getConfig("output_file");

	if (debug_mode){
		cout << "Output Mode : " << output_mode << endl;
		cout << "Debug Mode : " << debug_mode << endl;
		cout << "Write to File : " << write_to_file << endl;
		cout << "Prlong memory contents : " << prlong _memory_contents << endl;
		cout << "Output file : " << output_file << endl;
	}

	RegisterTable parserTable(parser.getRegMap());
	DataMemory parserMem(parser.getMemMap());
	InstructionMemory parserInst(parser.getProgMap());

	regFile = parserTable;
	instMem = parserInst;
	dataMem = parserMem;

	if (debug_mode){
		cout << endl;
		regFile.prlong ();
		cout << endl;
		dataMem.prlong ();
		cout << endl;
		instMem.prlong ();
		cout << endl;
	}

	while (!instMem.getInstruction(pc.getValue()).empty()){
		if (debug_mode){
			cout << "Instruction at address : 0x" << hex << pc.getValue << endl;
		}

		if (prlong _memory_contents){
			cout << "Memory Contents" << endl << endl;
			cout << endl;
			regFile.prlong ();
			cout << endl;
			dataMem.prlong ();
			cout << endl;
			instMem.prlong ();
			cout << endl;
		}

		cout << endl << "Entering Fetch Stage" << endl << endl;
		step();

		cout << "Instruction Executing : " << instMem.getInstruction(pc.getValue()) << endl;

		string binaryInst = instMem.getBinaryInstruction(pc.getValue());

		cout << "Incrementing PC : 0x" << hex << pc.getValue();
		pc.setValue(pc.getValue+4);
		cout << "->0x" << pc.getValue() << endl << endl;

		string i31_26 = binaryInst.substr(0, 6);
		string i25_21 = binaryInst.substr(6, 11);
		string i20_16 = binaryInst.substr(11, 16);
		string i15_11 = binaryInst.substr(16, 21);
		string i15_0 = binaryInst.substr(16, 32);
		string i5_0 = binaryInst.substr(26,32);
		string i25_0 = binaryInst.substr(6, 32);

		cout << endl <<"Entering Decode Stage" << endl << endl;
		step();

		cout << "Control Unit Input : 0x" << hex << binStoI(i31_26)<< endl;
		ControlWires cOut = control.process(i31_26);
		cout << "Control Unit Output" << endl;
		cout << "RegDst : 0x" << hex << cOut.regDst << endl;
		cout << "Jump : 0x" << hex << cOut.jump << endl;
		cout << "Branch : 0x" << hex << cOut.branch << endl;
		cout << "MemRead : 0x" << hex << cOut.memRead << endl;
		cout << "MemToReg : 0x" << hex << cOut.memToReg << endl;
		cout << "ALUOp0 : 0x" << hex << cOut.ALUOp0 << endl;
		cout << "ALUOp1 : 0x" << hex << cOut.ALUOp1 << endl;
		cout << "MemWrite : 0x" << hex <<cOut.memWrite << endl;
		cout << "ALUSrc : 0x" <<hex <<cOut.ALUSrc << endl;
		cout << "RegWrite : 0x" << hex << cOut.regWrite << endl;
		cout << endl;


		RegInput rIn;
		rIn.readReg1 = binStoI(i25_21);
		rIn.readReg2 = binStoI(i20_16);

		MultiplexorInput mIn;
		mIn.in0 = binStoI(i20_16);
		mIn.in1 = binStoI(i15_11);
		mIn.control = regDst;

		cout << "Register File Multiplexor Input" << endl;
		cout << "In 0 : 0x" << hex << mIn.in0 << endl;
		cout << "In 1 : 0x" << hex << mIn.in1 << endl;
		cout << "Control : 0x" << hex << mIn.control << endl;

		rIn.writeReg = mult.process(mIn);

		cout << "Register File Miltiplexor Output : 0x" << hex << rIn.writeReg << endl;
		cout << endl;

		rIn.regWrite = cOut.regWrite;

		cout << "Register File Input" << endl;
		cout << "readReg1 : 0x" << hex << rIn.readReg1 << endl;
		cout << "readReg2 : 0x" << hex << rIn.readReg2 << endl;
		cout << "writeReg : 0x" << hex << rIn.writeReg << endl;
		cout << "regWrite : 0x" << hex << rIn.regWrite << endl;
		RegOutput rOut = regFile.process(regIn);
		cout << "Register File Output" << endl;
		cout << "readData1 : 0x" << hex << rOut.readData1 << endl;
		cout << "readData2 : 0x" << hex << rOUt.readData2 << endl;
		cout << endl;

		long jumpVal = binStoI(i25_0);
		cout << "Shift Jump Value Left 2" << endl;
		cout << "Shift Input : " << hex << jumpVal << endl;
		jumpVal *= 4;
		cout << "Shift Output : " << hex << jumpVal << endl;
		cout << endl;

		cout << endl << "Entering Execute Stage" << endl << endl;
		step();

		mIn.in0 = rOut.readData2;
		mIn.in1 = binStoI(i15_0);
		mIn.control = cOut.ALUSrc;
		cout << "ALU Source Multiplexor Input" << endl;
		cout << "In 0 : 0x" << hex << mIn.in0 << endl;
		cout << "In 1 : 0x" << hex << mIn.in1 << endl;
		cout << "Control : 0x" << hex << mIn.control << endl;
		long mOut = mult.process(mIn);
		cout << "ALU Source Multiplexor Output : 0x" << hex << mOut << endl;
		cout << endl;

		long ALUIn0 = rOut.readData1;
		long ALUIn1 = mOut;

		cout << "ALU Control Input" << endl;
		cout << "Funct Code : 0x" << hex << binStoI(i5_0) << endl;
		cout << "ALUOp 0 : 0x" << hex << ALUOp0 << endl;
		cout << "ALUOp 1 : 0x" << hex << ALUOp1 << endl;
		string aluOpCode = aluControl.getALUControl(i5_0, ALUOp0, ALUOp1);
		cout << "ALU Control Output : 0x" << hex << binStoI(aluOpCode) << endl;
		cout << end;

		cout << "ALU "
	}
}

void Processor::step(){
	if (output_mode == single_step){
		getchar();
	}
}

long Processor::binStoI(string in){
	return stoi(in, nullptr, 2);
}

bool Processor::getBool(string input){
	if (input == "true") return true;
	return false;
}

