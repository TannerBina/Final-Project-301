#include "Utility.h"

using namespace std;

string Utility::htob(char hexChar){
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

		cout << "NOT A VALID HEX CHARACTER" << endl;
		return "0000";
	}	

	/*
	Converts a binary string to an integer
	 */
	int Utility::bStoi(string binaryString, bool isSigned){
		int result = 0;
		//loop through string
		for (unsigned int i = 0; i < binaryString.length(); i++){
			//check twos compliment first bit.
			if (i == 0 && isSigned){
				if (binaryString.at(i) == '1'){
					result -= pow(2, binaryString.length() - 1 - i);
				}
			} else {

				//otherwise add 2 to the power if value is 1.
				if (binaryString.at(i) == '1'){
					result += pow(2, binaryString.length() - 1 - i);
				}

			}
		}
		return result;
	}

	/*
	converts a hex to a signed integer
	 */
	int Utility::hStoi(string hexString){
		//convert hex to binary
		string binaryString;
		for (unsigned int i = 0; i < hexString.length(); i++){
			binaryString.append(htob(hexString[i]));
		}

		//convert binary to integer
		//is signed if 32 bit number
		return bStoi(binaryString, hexString.length() == 8);
	}