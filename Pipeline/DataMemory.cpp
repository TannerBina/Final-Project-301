#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory(map<long , long > initMem){
	map<long , long >::iterator it;
	for (it = initMem.begin(); it != initMem.end(); it++){
		memory[it->first] = it->second;
	}
}

long  DataMemory::process(MemInput in){
	if (in.memWrite){
		memory[in.address] = in.writeData;
	}
	if (in.memRead){
		return memory[in.address];
	}
	return 0;
}

void DataMemory::prlong (){
	map<long , long >::iterator it;
	cout << "Data Memory" << endl;
	for (it = memory.begin(); it != memory.end(); it++){
		cout << "0x" << hex << it->first << " : 0x" << hex << it->second << endl;
	}
}