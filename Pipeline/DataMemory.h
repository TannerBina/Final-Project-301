/*
Stores the memory and all data values in it.
all are stored at addresses
max address is 2^31
 */

#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include <map>
#include <string>
#include <iostream>

using namespace std;

//the normal input to the memory unit
struct MemInput{
	int  memWrite;
	int  memRead;
	int  address;
	int  writeData;
};

class DataMemory{
public:
	DataMemory(){}
	//creates memory input from map of addresses and values
	DataMemory(map<int , int > initMem);
	//process an input saving input and output and returning output
	int  process(MemInput in);

	//print input and output
	void print();
	//print all values stored in the memory
	void printAll ();

	//get the input and output
	MemInput getInput(){return input;}
	int getOutput(){return output;}
private:
	//stores the memory
	map<int , int > memory;

	//stores the input and output
	MemInput input;
	int output;
};

#endif