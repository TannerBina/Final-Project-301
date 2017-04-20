#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory(map<int , int > initMem){
	map<int , int >::iterator it;
	for (it = initMem.begin(); it != initMem.end(); it++){
		memory[it->first] = it->second;
	}
}

int  DataMemory::process(MemInput in){
	input = in;

	if (in.memWrite){
		memory[in.address] = in.writeData;
	}
	if (in.memRead){
		output = memory[in.address];
		return memory[in.address];
	}
	output = 0;
	return 0;
}

void DataMemory::print(){
	cout << "Input" << endl;
	cout << "MemWrite : 0x" << hex << input.memWrite << endl;
	cout << "MemRead : 0x" << hex << input.memRead << endl;
	cout << "Address : 0x" << hex << input.address << endl;
	cout << "WriteData : 0x" << hex << input.writeData << endl;
	cout << "Output : 0x" << hex << output << endl;
}

void DataMemory::printAll (){
	map<int , int >::iterator it;
	cout << "Data Memory" << endl;
	for (it = memory.begin(); it != memory.end(); it++){
		cout << "0x" << hex << it->first << " : 0x" << hex << it->second << endl;
	}
}