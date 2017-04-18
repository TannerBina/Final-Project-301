#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

struct MultiplexorInput{
	long in0;
	long in1;
	long control;
};

class Multiplexor{
public:
	Multiplexor();

	long process(MultiplexorInput in){
		if (in.control == 0){
			return in.in0;
		} else {
			return in.in1;
		}
	}
};

#endif