#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include <map>
#include <string>
#include <iostream>

using namespace std;

struct MemInput{
	long  memWrite;
	long  memRead;
	long  address;
	long  writeData;
};

class DataMemory{
public:
	DataMemory(){}
	DataMemory(map<long , long > initMem);
	long  process(MemInput in);

	void prlong ();
private:
	map<long , long > memory;

};

#endif