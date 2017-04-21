/*
Holds the current value of the pc
 */

#ifndef __PC_H__
#define __PC_H__

class PC {
private:
	//stores pc value
	 int value;
public:
	//intialize pc to starting index of program
	PC(){
		value = 0x400000;
	}

	//setvalue of pc
	void setValue(int newValue);

	//get value of pc
	 int getValue();
};

#endif