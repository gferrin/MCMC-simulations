#include <iostream>
#include <iomanip>
#include "../../Libs/C++/heapsort.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/common_raset1.h"
#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/razero.h"
#include "../../Libs/C++/qdf_gnu.h"

using namespace std;

int main(void)
{
	// after program is finished being written check to make sure that
	// all of these variables are being used, I'm fairly certain some of 
	// them server no other purpose then formating the FORTRAN code 
	const double one = 1.000000;
	const int numberPoll = 10000, numberData = 700, NCH = 3, NCP1 = NCH + 1;
	int IUO = 6, IUD = 10, ISD1 = 1, ISD2 = 0, M1 = -1;
	struct Common block;

	double probability[NCH] = {.42,.38,.16}, cumulativeProb[NCP1], score[NCP1];
	double result[numberPoll][NCP1];
	int IWI1 = 0, IWI2 = 0, ITIE = 0;
	bool Ltest = true;

	// make sure probablility is sorted from greatest to least
	// this makes the rest of the code execute faster given a sufficiently large data set
	Heapsort(probability, NCH); // this is the oposit of that so reverse
	double tempArray[NCH];
	for(int k = 0; k < NCH; k++){
		tempArray[k] = probability[(NCH - 1) - k];
	} // now store it back in probability array 
	for(int n = 0; n < NCH; n++){
		probability[n] = tempArray[n];
	}
	
	cout << "\nProgram polls (polls.f):\n" << endl; // figure out how to format all this stuff

	cumulativeProb[0] = probability[0]; // Calculate cumulative probabilities.

	for(int i = 1; i < NCH; i++){
		cumulativeProb[i] = cumulativeProb[i - 1] + probability[i];
	}
	cumulativeProb[NCP1-1] = one;

	rmaset(block); // initilize random block

	for(int IPoll = 0; IPoll < numberPoll; IPoll++){
		// set the array of score to zero 
		razero(score,  NCP1);
		for(int IData = 1; IData <= numberData; IData++){
			// get a random number
			double tempRandom = ranmar(block);
			
			for(int i = 0; i < NCP1; i++){
				if( tempRandom < cumulativeProb[i]){
					score[i] += 1;
					break;
				}
			}
		}
		for(int i = 0; i < NCP1; i++){
			result[IPoll][i] = ( score[i] / numberData );
		}
		if(score[0] > score[1]){
			IWI1++;
		} else if(score[0] == score[1]){
			ITIE++;
		} else {
			IWI2++;
		}
	}

	cout << "Bush: " << IWI1 << " Clinton: " << IWI2 << " Tie: " << ITIE << endl;

	double P1 = (one*IWI1+.5*ITIE)/(one*(IWI1+IWI2+ITIE));
	double P2 = (one*IWI2+.5*ITIE)/(one*(IWI1+IWI2+ITIE));

	cout << "P1: " << P1 << " P2: " << P2 << endl; 

	for(int i = 0; i < NCP1; i++){
		double tempArray[numberPoll];
		for(int j = 0; j < numberPoll; j++){
			tempArray[j] = result[j][i];
		}
		// sort the data
		Heapsort(tempArray, numberPoll);
		// create plots for data (gnuplot)
		qdf_gnu(tempArray, numberPoll, i);
	}	

	cout << "All done: qdf data and plot files created.\n" << endl;

	return 0;
}