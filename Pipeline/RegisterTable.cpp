#include "RegisterTable.h"

using namespace std;

//initialize based on a map
RegisterTable::RegisterTable(map<int , int > initMap)
:writeState(false), writeRegister(-1){
	for (int i = 0; i < 32; i++){
		registers[i] = initMap[i];
	}
}

//process on input cycle to the register, outputting the read data
RegOutput RegisterTable::process(RegInput in){
	input = in;
	RegOutput res;

	//initialize read data to 0
	res.readData1 = 0;
	res.readData2 = 0;

	//if given a readReg input data in reg to output
	if (in.readReg1 > -1){
		res.readData1 = registers[in.readReg1];
	}
	if (in.readReg2 > -1){
		res.readData2 = registers[in.readReg2];
	}

	//set write state and write register for writing later on.
	writeState = in.regWrite;
	writeRegister = in.writeReg;
	output = res;

	//return output.
	return res;
}

//process the writeback cycle, true if written to register.
bool RegisterTable::write(int writeData){
	//tries to write to a register, returns true if successfull, false otherwise.
	writeInput = writeData;
	if (writeRegister != -1 && writeState){
		registers[writeRegister] = writeData;
		return true;
	}
	return false;
}

//prints all registers and contents.
void RegisterTable::printAll (){
	cout << "Register File" << endl;
	for (int i = 0; i < 32; i++){
		cout << "Register " << i << " : 0x" << hex << registers[i] << endl;
	}
}

//print the input and outputs to the register file
void RegisterTable::print(){
	cout << "Input" << endl;
	cout << "ReadReg1 : 0x" << hex << input.readReg1 << endl;
	cout << "ReadReg2 : 0x" << hex << input.readReg2 << endl;
	cout << "WriteReg : 0x" << hex << input.writeReg << endl;
	cout << "RegWrite : 0x" << hex << input.regWrite << endl;
	cout << "Output" << endl;
	cout << "ReadData1 : 0x" << hex << output.readData1 << endl;
	cout << "ReadData2 : 0x" << hex << output.readData2 << endl;
}

//print the inputs to a write command of the register file.
void RegisterTable::printWrite(){
	cout << "Input" << endl;
	cout << "WriteInput : 0x" << hex << writeInput << endl;
	cout << "WriteState : 0x" << hex << writeState << endl;
	cout << "WriteRegister : 0x" << hex << writeRegister << endl; 
}