/*
Implements the data memory
 */

#include "DataMemory.h"

using namespace std;

/*
Create data memory from a map of addresses and values
 */
DataMemory::DataMemory(map<int , int > initMem){
	//copy map
	map<int , int >::iterator it;
	for (it = initMem.begin(); it != initMem.end(); it++){
		memory[it->first] = it->second;
	}
}

//process an input
int  DataMemory::process(MemInput in){
	//save input
	input = in;

	//write to memory if control is 1
	if (in.memWrite){
		memory[in.address] = in.writeData;
	}
	//save output and output adress value
	if (in.memRead){
		output = memory[in.address];
		return memory[in.address];
	}
	output = 0;
	return 0;
}

//print the input and output
void DataMemory::print(){
	cout << "Input" << endl;
	cout << "MemWrite : 0x" << hex << input.memWrite << endl;
	cout << "MemRead : 0x" << hex << input.memRead << endl;
	cout << "Address : 0x" << hex << input.address << endl;
	cout << "WriteData : 0x" << hex << input.writeData << endl;
	cout << "Output : 0x" << hex << output << endl;
}

//print all values stored in the data memory
void DataMemory::printAll (){
	map<int , int >::iterator it;
	cout << "Data Memory" << endl;
	for (it = memory.begin(); it != memory.end(); it++){
		cout << "0x" << hex << it->first << " : 0x" << hex << it->second << endl;
	}
}