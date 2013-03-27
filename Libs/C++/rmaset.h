#ifndef RMASET_H_
#define RMASET_H_

#include "common_raset1.h"
#include <fstream>
#include <string>

using namespace std;

bool rmaset(Common &block, int seed1 = 1, int seed2 = 0, std::string filename = "ranmar.txt" );

bool rmaset(Common &block, int seed1, int seed2, std::string filename )
{ 
	bool file = false;

	ifstream inStream( filename.c_str() );

	if(inStream.fail()){ // if the file does not exist give it values
 
		double ZERO = 0.0, HALF = 0.5;
		int value1 = seed1 + 1801;
		int value2 = seed2 + 9373;

		block.I = ((value1/177) % 177) + 2;
		block.J = (value1 % 177) + 2;
		int K = ((value2/169) % 178) + 1;
		int M = value2 % 169;
		int N;

		for(int y = 0; y < 97; y++ ){
			double S = ZERO;
			double T = HALF;
			// same with this for loop
			for(int x = 0; x < 24; x++){
				N = (((block.I*block.J) % 179) * K ) % 179;
				block.I = block.J;
				block.J = K;
				K = N;
				M = (53*M+1) % 169;
				if(((M*N) % 64) >= 32 ) S+=T;
				T = HALF * T;
			}// end of nested for loop
			// now add S to the array
			block.U[y] = S;
		} //end of first for loop
		block.C = (362436.0/16777216.0);
		block.CD = 7654321.0/16777216.0;
		block.CM = 16777213.0/16777216.0;
		block.I = 96;
		block.J = 32;

		cout << "\n RANMAR INITIALIZED.\n" << endl;

		file = false; // give file a value of false if it does not exist

	} else { // otherwise extract the values from the file
		int counter = 0;
		string value;
		while(!inStream.eof()){
			getline(inStream,value,',');
			if( counter < 97){
				double S = atof(value.c_str());
				block.U[counter] = S;
				counter++;
			} else {
				if(counter == 97){
					int I = int(atof(value.c_str()));
					block.I = I;
					counter++;
				} else if (counter == 98){
					int J = int(atof(value.c_str()));
					block.J = J;
					counter++;
				} else if( counter == 99){
					double C = atof(value.c_str());
					block.C = C;
					counter++;
				} else if( counter == 100){
					double CD = atof(value.c_str());
					block.CD = CD;
					counter++;
				} else {
					double CM = atof(value.c_str());
					block.CM = CM;
					break;
				}
			}
		} // end of while loop
		cout << "\n MARSAGLIA CONTINUATION.\n" << endl;
		
		file = true; // true if it does exist
	}
	// close the file
	inStream.close();

	return file;
}


#endif /* RMASET_H_ */

