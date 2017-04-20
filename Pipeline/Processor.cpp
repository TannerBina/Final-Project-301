#include "Processor.h"


using namespace std;


Processor::Processor()
:output_mode("single_step"), debug_mode(false), print_memory_contents(false), write_to_file(false){

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
	print_memory_contents = getBool(parser.getConfig("print_memory_contents"));
	output_file = parser.getConfig("output_file");

	if (debug_mode){
		cout << "Output Mode : " << output_mode << endl;
		cout << "Debug Mode : " << debug_mode << endl;
		cout << "Write to File : " << write_to_file << endl;
		cout << "Print memory contents : " << print_memory_contents << endl;
		cout << "Output file : " << output_file << endl;
	}

	RegisterTable parserTable(parser.getRegMap());
	DataMemory parserMem(parser.getMemMap());
	InstructionMemory parserInst(parser.getProgMap(), parser.getBinProg());

	regFile = parserTable;
	instMem = parserInst;
	dataMem = parserMem;

	if (debug_mode){
		cout << endl;
		regFile.printAll();
		cout << endl;
		dataMem.printAll();
		cout << endl;
		instMem.printAll();
		cout << endl;
	}
	
	while (!instMem.getInstruction(pc.getValue()).empty()){
		if (debug_mode){
			cout << "Instruction at address : 0x" << hex << pc.getValue() << endl;
		}

		step();

		if (print_memory_contents){
			cout << "Printing Memory Contents" << endl;
			regFile.printAll();
			cout << endl;
			dataMem.printAll();
			cout << endl;
			instMem.printAll();
			cout << endl;
		}

		cout << endl << "Entering Fetch Stage" << endl << endl;
		if (debug_mode) step();

		instMem.getInstruction(pc.getValue());
		instMem.getBinaryInstruction(pc.getValue());

		cout << "InstructionMemory Instruction Fetched" << endl;
		instMem.printInst();
		cout << "InstructionMemory Instruction" << endl;
		instMem.printBin();
		cout << endl;

		string i31_26 = instMem.getBinOutput().substr(0, 6);
		string i25_21 = instMem.getBinOutput().substr(6, 11);
		string i20_16 = instMem.getBinOutput().substr(11, 16);
		string i15_11 = instMem.getBinOutput().substr(16, 21);
		string i15_0 = instMem.getBinOutput().substr(16, 32);
		string i5_0 = instMem.getBinOutput().substr(27, 32);
		string i25_0 = instMem.getBinOutput().substr(6,32);

		if (debug_mode){
			cout << "Instruction : " << instMem.getBinOutput() << endl;
			cout << "i31_26 : " << i31_26 << endl;
			cout << "i25_21 : " << i25_21 << endl;
			cout << "i20_16 : " << i20_16 << endl;
			cout << "i15_11 : " << i15_11 << endl;
			cout << "i15_0 : " << i15_0 << endl;
			cout << "i25_0 : " << i25_0 << endl;
			cout << "i5_0 : " << i5_0 << endl << endl;
		}

		pcAddALU.performALU("010", pc.getValue(), 4);

		cout << "PC ALU" << endl;
		pcAddALU.print();
		cout << endl;

		cout << endl << "Entering Decode Stage" << endl << endl;
		if (debug_mode) step();

		control.process(i31_26);

		cout << "Control Unit" << endl;
		control.print();
		cout << endl;

		MultiplexorInput mInReg;
		mInReg.in0 = Utility::bStoi(i20_16);
		mInReg.in1 = Utility::bStoi(i15_11);
		mInReg.control = control.getOutput().regDst;
		regMult.process(mInReg);

		cout << "Destination Register Multiplexor" << endl;
		regMult.print();
		cout << endl;

		RegInput rIn;
		rIn.readReg1 = Utility::bStoi(i25_21);
		rIn.readReg2 = Utility::bStoi(i20_16);
		rIn.writeReg = regMult.getOutput();
		rIn.regWrite = control.getOutput().regWrite;
		regFile.process(rIn);

		cout << "Register File" << endl;
		regFile.print();
		cout << endl;

		signExtend.extendToThirtyTwo(Utility::bStoi(i15_0));

		cout << "Sign Extend" << endl;
		signExtend.print();
		cout << endl;

		jumpShift.performShiftLeft(Utility::bStoi(i25_0));

		cout << "Jump Shift Left" << endl;
		jumpShift.print();
		cout << endl;

		int jumpVal = pcAddALU.getOutput().output & 0x10000000;
		jumpVal += jumpShift.getOutput();

		cout << endl << "Entering Execute Stage" << endl << endl;
		if (debug_mode) step();

		aluControl.getALUControl(i5_0, control.getOutput().ALUOp0, control.getOutput().ALUOp1);

		cout << "ALU Control" << endl;
		aluControl.print();
		cout << endl;

		MultiplexorInput mInALU;
		mInALU.in0 = regFile.getOutput().readData1;
		mInALU.in1 = regFile.getOutput().readData2;
		mInALU.control = control.getOutput().ALUSrc;
		aluMult.process(mInALU);

		cout << "ALU Multiplexor" << endl;
		aluMult.print();
		cout << endl;

		mainALU.performALU(aluControl.getOutput(), aluMult.getOutput(), regFile.getOutput().readData1);
		
		cout << "Main ALU" << endl;
		mainALU.print();
		cout << endl;

		branchShift.performShiftLeft(signExtend.getOutput());

		cout << "Branch Shift" << endl;
		branchShift.print();
		cout << endl;

		branchALU.performALU("010", pcAddALU.getOutput().output, branchShift.getOutput());

		cout << "Branch ALU" << endl;
		branchALU.print();
		cout << endl;

		cout << endl << "Entering Memory Stage" << endl << endl;
		if (debug_mode) step();

		MemInput memIn;
		memIn.address = mainALU.getOutput().output;
		memIn.writeData = regFile.getOutput().readData2;
		memIn.memWrite = control.getOutput().memWrite;
		memIn.memRead = control.getOutput().memRead;
		dataMem.process(memIn);

		cout << "Data Memory" << endl;
		dataMem.print();
		cout << endl;

		int branchMultVal = control.getOutput().branch & mainALU.getOutput().zeroOrOne;
		cout << "Branch And Gate" << endl;
		cout << "Input" << endl;
		cout << "In0 : 0x" << hex << control.getOutput().branch << endl;
		cout << "In1 : 0x" << hex << mainALU.getOutput().zeroOrOne << endl;
		cout << "Output : 0x" << hex << branchMultVal << endl;
		cout << endl;

		MultiplexorInput branchMultIn;
		branchMultIn.in0 = pcAddALU.getOutput().output;
		branchMultIn.in1 = branchALU.getOutput().output;
		branchMultIn.control = branchMultVal;
		branchMult.process(branchMultIn);

		cout << "Branch Multiplexor" << endl;
		branchMult.print();
		cout << endl;

		cout << "Entering Writeback Stage" << endl;
		if (debug_mode) step();

		MultiplexorInput writeBackMultIn;
		writeBackMultIn.in0 = mainALU.getOutput().output;
		writeBackMultIn.in1 = dataMem.getOutput();
		writeBackMultIn.control = control.getOutput().memToReg;
		writeBackMult.process(writeBackMultIn);

		cout << "Write Back Multiplexor" << endl;
		writeBackMult.print();
		cout << endl;

		regFile.write(writeBackMult.getOutput());
		cout << "Reg File Writeback" << endl;
		regFile.printWrite();
		cout << endl;

		MultiplexorInput jumpMultIn;
		jumpMultIn.in0 = branchMult.getOutput();
		jumpMultIn.in1 = jumpVal;
		jumpMultIn.control = control.getOutput().jump;
		jumpMult.process(jumpMultIn);

		cout << "Jump Multiplexor" << endl;
		jumpMult.print();
		cout << endl;

		pc.setValue(jumpMult.getOutput());
	}
}

void Processor::step(){
	if (output_mode == "single_step" || debug_mode){
		cout << "Press Enter to Continue" << endl;
		getchar();
	}
}

bool Processor::getBool(string input){
	if (input == "true") return true;
	return false;
}

int main(){
	Processor proc("input.config");
	return 0;
}


