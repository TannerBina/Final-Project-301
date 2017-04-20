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
	res.readData1 = 0;
	res.readData2 = 0;
	if (in.readReg1 > -1){
		res.readData1 = registers[in.readReg1];
	}
	if (in.readReg2 > -1){
		res.readData2 = registers[in.readReg2];
	}
	writeState = in.regWrite;
	writeRegister = in.writeReg;
	output = res;
	return res;
}

//process the writeback cycle, true if written to register.
bool RegisterTable::write(int writeData){
	writeInput = writeData;
	if (writeRegister != -1 && writeState){
		registers[writeRegister] = writeData;
		return true;
	}
	return false;
}

void RegisterTable::printAll (){
	cout << "Register File" << endl;
	for (int i = 0; i < 32; i++){
		cout << "Register " << i << " : 0x" << hex << registers[i] << endl;
	}
}

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

void RegisterTable::printWrite(){
	cout << "Input" << endl;
	cout << "WriteInput : 0x" << hex << writeInput << endl;
	cout << "WriteState : 0x" << hex << writeState << endl;
	cout << "WriteRegister : 0x" << hex << writeRegister << endl; 
}