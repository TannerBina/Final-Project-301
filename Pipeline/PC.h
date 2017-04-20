#ifndef __PC_H__
#define __PC_H__

class PC {
private:
	 int value;
public:
	PC(){
		value = 0x400000;
	}

	void setValue(int newValue){
		value = newValue;
	}

	 int getValue(){
		return value;
	}
};

#endif