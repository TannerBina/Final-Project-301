#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include <map>
#include <string>
#include <iostream>

using namespace std;

struct MemInput{
	int  memWrite;
	int  memRead;
	int  address;
	int  writeData;
};

class DataMemory{
public:
	DataMemory(){}
	DataMemory(map<int , int > initMem);
	int  process(MemInput in);

	void print();
	void printAll ();

	MemInput getInput(){return input;}
	int getOutput(){return output;}
private:
	map<int , int > memory;

	MemInput input;
	int output;
};

#endif