#include "RegisterTable.h"

using namespace std;

//initialize based on a map
RegisterTable::RegisterTable(map<int, int> initMap)
:writeState(false), writeRegister(-1){
	for (int i = 0; i < 32; i++){
		registers[i] = initMap[i];
	}
}

//process on input cycle to the register, outputting the read data
RegOutput RegisterTable::process(RegInput in){
	RegOutput res;
	if (in.readReg1 > -1){
		res.readData1 = registers[in.readReg1];
	}
	if (in.readReg2 > -1){
		res.readData2 = registers[in.readReg2];
	}
	writeState = in.regWrite;
	writeRegister = in.writeReg;
	return res;
}

//process the writeback cycle, true if written to register.
bool RegisterTable::write(int writeData){
	if (writeRegister != -1 && writeState){
		registers[writeRegister] = writeData;
		return true;
	}
	return false;
}