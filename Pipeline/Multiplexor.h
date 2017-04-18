#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

struct MultiplexorInput{
	int in0;
	int in1;
	int control;
};

class Multiplexor{
public:
	Multiplexor();

	int process(MultiplexorInput in){
		if (in.control == 0){
			return in.in0;
		} else {
			return in.in1;
		}
	}
};

#endif