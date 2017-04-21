#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include <cmath>
#include <iostream>

using namespace std;


/*
Utility class which provides functions to conver hex and binary to integers.
 */
class Utility{

public:
	/*
	Returns the 4 binary bits from the given hex char
	 */
	static string htob(char hexChar);

	/*
	Converts a binary string to an integer
	 */
	static int bStoi(string binaryString, bool isSigned);

	/*
	converts a hex to a signed integer
	 */
	static int hStoi(string hexString);


};

#endif