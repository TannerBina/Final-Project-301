#include "Processor.h"
#include <stdio.h>


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

	//get the config values for each initialization variable
	output_mode = parser.getConfig("output_mode");
	debug_mode = getBool(parser.getConfig("debug_mode"));
	write_to_file = getBool(parser.getConfig("write_to_file"));
	print_memory_contents = getBool(parser.getConfig("print_memory_contents"));
	output_file = parser.getConfig("output_file");

	if (write_to_file){
		freopen(output_file.c_str(), "w", stdout);
	}

	//if debug print out all modes
	if (debug_mode){
		cout << "Output Mode : " << output_mode << endl;
		cout << "Debug Mode : " << debug_mode << endl;
		cout << "Write to File : " << write_to_file << endl;
		cout << "Print memory contents : " << print_memory_contents << endl;
		cout << "Output file : " << output_file << endl;
	}

	//set up the register file, inttruction memeor, and data memory
	RegisterTable parserTable(parser.getRegMap());
	DataMemory parserMem(parser.getMemMap());
	InstructionMemory parserInst(parser.getProgMap(), parser.getBinProg());

	regFile = parserTable;
	instMem = parserInst;
	dataMem = parserMem;

	//if debug print out all files
	if (debug_mode){
		cout << endl;
		regFile.printAll();
		cout << endl;
		dataMem.printAll();
		cout << endl;
		instMem.printAll();
		cout << endl;
	}

	//while there is an instruction at the current pc value, run the instruction
	while (!instMem.getInstruction(pc.getValue()).empty()){
		//if debug print instruction address.
		if (debug_mode){
			cout << "Instruction at address : 0x" << hex << pc.getValue() << endl;
		}

		//wait for user input
		step();

		//print memeory contents at beginning of execution
		if (print_memory_contents){
			cout << "Printing Memory Contents" << endl;
			regFile.printAll();
			cout << endl;
			dataMem.printAll();
			cout << endl;
			instMem.printAll();
			cout << endl;
		}

		//enters fetching stage
		cout << endl << "Entering Fetch Stage" << endl << endl;
		if (debug_mode) step();

		//get the instruction and the binary of the instruction
		instMem.getInstruction(pc.getValue());
		instMem.getBinaryInstruction(pc.getValue());

		//prints out instructions
		cout << "InstructionMemory Instruction Fetched" << endl;
		instMem.printInst();
		cout << "InstructionMemory Instruction" << endl;
		instMem.printBin();
		cout << endl;

		//split binary instruction into smaller parts
		string i31_26 = instMem.getBinOutput().substr(0, 6);
		string i25_21 = instMem.getBinOutput().substr(6, 5);
		string i20_16 = instMem.getBinOutput().substr(11, 5);
		string i15_11 = instMem.getBinOutput().substr(16, 5);
		string i15_0 = instMem.getBinOutput().substr(16, 16);
		string i5_0 = instMem.getBinOutput().substr(27, 5);
		string i25_0 = instMem.getBinOutput().substr(6, 26);

		//if debug print out all binary splits of instruction
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

		//add 4 to the pc store in add alu
		pcAddALU.performALU("010", pc.getValue(), 4);

		//print out pc alu
		cout << "PC ALU" << endl;
		pcAddALU.print();
		cout << endl;

		//enter the decode stage.
		cout << endl << "Entering Decode Stage" << endl << endl;
		if (debug_mode) step();

		//sent the op code to the control store lines in control
		control.process(i31_26);

		//print out control
		cout << "Control Unit" << endl;
		control.print();
		cout << endl;

		//settup into into reg mutliplexor from binary instruction
		MultiplexorInput mInReg;
		mInReg.in0 = Utility::bStoi(i20_16);
		mInReg.in1 = Utility::bStoi(i15_11);
		//get control wire and process
		mInReg.control = control.getOutput().regDst;
		regMult.process(mInReg);

		//print out multiplexor
		cout << "Destination Register Multiplexor" << endl;
		regMult.print();
		cout << endl;

		//get input from binary instruction and multiplexor result.
		RegInput rIn;
		rIn.readReg1 = Utility::bStoi(i25_21);
		rIn.readReg2 = Utility::bStoi(i20_16);
		rIn.writeReg = regMult.getOutput();
		//get regwrite from control wire and process
		rIn.regWrite = control.getOutput().regWrite;
		regFile.process(rIn);

		//print out register file
		cout << "Register File" << endl;
		regFile.print();
		cout << endl;

		//sign extend the immediate to 32 bits
		signExtend.extendToThirtyTwo(Utility::bStoi(i15_0));

		//print out the sign extend
		cout << "Sign Extend" << endl;
		signExtend.print();
		cout << endl;

		//shift the jump value from the binary ofver 2
		jumpShift.performShiftLeft(Utility::bStoi(i25_0));

		//print out jump shift unit
		cout << "Jump Shift Left" << endl;
		jumpShift.print();
		cout << endl;

		//calculate jump value from first four of pc and jumpshfited value
		int jumpVal = pcAddALU.getOutput().output & 0x10000000;
		jumpVal += jumpShift.getOutput();

		//entering the execution stage
		cout << endl << "Entering Execute Stage" << endl << endl;
		if (debug_mode) step();

		//input the op code, alu op 0 from control and alu op 1 from control to alu control
		aluControl.getALUControl(i5_0, control.getOutput().ALUOp0, control.getOutput().ALUOp1);

		//print out alu control
		cout << "ALU Control" << endl;
		aluControl.print();
		cout << endl;

		//settup alu multiplexor from register output 2 and sign extend
		MultiplexorInput mInALU;
		mInALU.in0 = regFile.getOutput().readData2;
		mInALU.in1 = signExtend.getOutput();
		//get control wire from the control and process
		mInALU.control = control.getOutput().ALUSrc;
		aluMult.process(mInALU);

		//print out multiplexor
		cout << "ALU Multiplexor" << endl;
		aluMult.print();
		cout << endl;

		//perfor alu on alu multiplexor and read data 1 with control wire from alu control
		mainALU.performALU(aluControl.getOutput(), aluMult.getOutput(), regFile.getOutput().readData1);
		
		//print out the main alu vlaues
		cout << "Main ALU" << endl;
		mainALU.print();
		cout << endl;

		//shift the branch value over by two from the isgn extend output
		branchShift.performShiftLeft(signExtend.getOutput());

		//print out the branch shift
		cout << "Branch Shift" << endl;
		branchShift.print();
		cout << endl;

		//add the pc +4 value to the branch value
		branchALU.performALU("010", pcAddALU.getOutput().output, branchShift.getOutput());

		//print out the branch alu
		cout << "Branch ALU" << endl;
		branchALU.print();
		cout << endl;

		//enter the memeory stage
		cout << endl << "Entering Memory Stage" << endl << endl;
		if (debug_mode) step();

		//get meme input from main alu, reg file
		MemInput memIn;
		memIn.address = mainALU.getOutput().output;
		memIn.writeData = regFile.getOutput().readData2;
		//get wires for memwrite and memread from control
		memIn.memWrite = control.getOutput().memWrite;
		memIn.memRead = control.getOutput().memRead;
		//process all
		dataMem.process(memIn);

		//print out the data memeory
		cout << "Data Memory" << endl;
		dataMem.print();
		cout << endl;

		//calcuate the branch and gate from control and 0 output for beq
		int branchMultVal = control.getOutput().branch & mainALU.getOutput().zeroOrOne;
		//print out and gate
		cout << "Branch And Gate" << endl;
		cout << "Input" << endl;
		cout << "In0 : 0x" << hex << control.getOutput().branch << endl;
		cout << "In1 : 0x" << hex << mainALU.getOutput().zeroOrOne << endl;
		cout << "Output : 0x" << hex << branchMultVal << endl;
		cout << endl;

		//get the branch multiplexor input from pc+4 and branch value
		MultiplexorInput branchMultIn;
		branchMultIn.in0 = pcAddALU.getOutput().output;
		branchMultIn.in1 = branchALU.getOutput().output;
		//get control from branch mult value
		branchMultIn.control = branchMultVal;
		//process
		branchMult.process(branchMultIn);

		//print out the branch multiplexor
		cout << "Branch Multiplexor" << endl;
		branchMult.print();
		cout << endl;

		//enter the writeback stage
		cout << "Entering Writeback Stage" << endl;
		if (debug_mode) step();

		//settup the multiplexor input for writeback
		MultiplexorInput writeBackMultIn;
		//get from main alu and dataMem
		writeBackMultIn.in0 = mainALU.getOutput().output;
		writeBackMultIn.in1 = dataMem.getOutput();
		//get control wire and process
		writeBackMultIn.control = control.getOutput().memToReg;
		writeBackMult.process(writeBackMultIn);

		//print out multiplexor
		cout << "Write Back Multiplexor" << endl;
		writeBackMult.print();
		cout << endl;

		//write back to reg file from multiplexor output
		regFile.write(writeBackMult.getOutput());
		cout << "Reg File Writeback" << endl;

		//print out.
		regFile.printWrite();
		cout << endl;

		//settup jump multiplex from branch multiplexor and jumpval
		MultiplexorInput jumpMultIn;
		jumpMultIn.in0 = branchMult.getOutput();
		jumpMultIn.in1 = jumpVal;
		//get control wire and process
		jumpMultIn.control = control.getOutput().jump;
		jumpMult.process(jumpMultIn);

		//print out jump multiplexor
		cout << "Jump Multiplexor" << endl;
		jumpMult.print();
		cout << endl;

		//set the value of the pc to the final multiplexor output.
		pc.setValue(jumpMult.getOutput());
	}

	fclose(stdout);
}

//waits for input if single step or debug mode
void Processor::step(){
	if (output_mode == "single_step" || debug_mode){
		cout << "Press Enter to Continue" << endl;
		getchar();
	}
}

//get the boolean from the string
bool Processor::getBool(string input){
	if (input == "true") return true;
	return false;
}

int main(int argc, char* argv[]){
	Processor proc(argv[1]);
	return 0;
}


