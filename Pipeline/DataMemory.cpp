#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory(map<int, int> initMem){
	map<int, int>::iterator it;
	for (it = initMem.begin(); it != initMem.end(); it++){
		memory[it->first] = it->second;
	}
}

int DataMemory::process(MemInput in){
	if (in.memWrite){
		memory[in.address] = in.writeData;
	}
	if (in.memRead){
		return memory[in.address];
	}
	return 0;
}

void DataMemory::print(){
	map<int, int>::iterator it;
	for (it = memory.begin(); it != memory.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}
}