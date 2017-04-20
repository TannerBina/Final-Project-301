#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include <cmath>

using namespace std;

class Utility{

public:
	static string htob(char hexChar){
		switch (hexChar){
			case '0':
			return "0000";
			break;

			case '1':
			return "0001";
			break;

			case '2':
			return "0010";
			break;

			case '3':
			return "0011";
			break;

			case '4':
			return "0100";
			break;

			case '5':
			return "0101";
			break;
			
			case '6':
			return "0110";
			break;

			case '7':
			return "0111";
			break;

			case '8':
			return "1000";
			break;

			case '9':
			return "1001";
			break;

			case 'a':
			case 'A':
			return "1010";
			break;

			case 'b':
			case 'B':
			return "1011";
			break;

			case 'c':
			case 'C':
			return "1100";
			break;

			case 'd':
			case 'D':
			return "1101";
			break;

			case 'e':
			case 'E':
			return "1110";
			break;

			case 'f':
			case 'F':
			return "1111";
			break;
		}
	}	

	static int bStoi(string binaryString){
		int result = 0;
		for (int i = 0; i < binaryString.length(); i++){
			if (i == 0 && binaryString.length() == 32){
				if (binaryString.at(i) == '1'){
					result -= pow(2, binaryString.length() - 1 - i);
				}
			} else {
				if (binaryString.at(i) == '1'){
					result += pow(2, binaryString.length() - 1 - i);
				}
			}
		}
		return result;
	}

	static int hStoi(string hexString){
		string binaryString;
		for (int i = 0; i < hexString.length(); i++){
			binaryString.append(htob(hexString[i]));
		}
		return bStoi(binaryString);
	}
};

#endif