#include <iostream>
#include <math.h>
#include <iomanip>
#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/common_raset1.h"

using namespace std;

int main(void)
{
	int numTrials = 11, seed1 = 1, seed2 = 0, sampleSize, counter;
	double probabilityRange = 4.0/10.0, two = 2.0, zero = 0.0,  probability, randomNum, error;
	struct Common block;

	cout << "\nProgram Sampling (sampling.cpp):\n" << endl;

	rmaset(block,seed1,seed2);

	cout << "ILLUSTRATION OF SAMPLING\n" << endl;

	for(int i = 1; i <= numTrials; i++){
		sampleSize = pow(two, ((2 * i) - 1));
		counter = 0;

		for(int j = 0; j < sampleSize; j++){
			randomNum = ranmar(block);

			if( randomNum < probabilityRange){
				counter++;
			}
		}
		probability = (counter*1.0)/(sampleSize * 1.0);
		error = (probability - probabilityRange);
		
		if( error < zero ){ error *= -1.0; }
		// Formating output 
		cout << "n, #Trials, Probability, Error: ";
		cout.precision(6);
		cout.width(7); cout  << left <<  i << right << sampleSize << '\t';
		cout << fixed << setw(12) << probability << "   " << scientific << error << endl;
	}
	cout << endl;

	return 0;
}