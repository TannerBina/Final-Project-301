#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include <map>
#include <string>

using namespace std;

struct MemInput{
	int memWrite;
	int memRead;
	string address;
	int writeData;
};

class DataMemory{
public:
	DataMemory(){}
	DataMemory(map<int, int> initMem);
	int process(MemInput in);

	void print();
private:
	map<int, int> memory;

};

#endif