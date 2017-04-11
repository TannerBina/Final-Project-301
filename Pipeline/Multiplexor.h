#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

struct MultiplexorInput{
	int in1;
	int in2;
};

class Multiplexor{
public:
	Multiplexor();

	int process(MultiplexorInput in, int control){
		if (control == 0){
			return in.in1;
		} else {
			return in.in2;
		}
	}
};

#endif