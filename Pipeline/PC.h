#ifndef __PC_H__
#define __PC_H__

class PC {
private:
	long value;
public:
	PC(){
		value = 0x400000;
	}

	void setValue(long newValue){
		value = newValue;
	}

	long getValue(){
		return value;
	}
};

#endif