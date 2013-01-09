/*
 * rmaset.cpp
 *
 *  Created on: Sep 4, 2012
 *      Author: Gabriel Ferrin
 */

#include <iostream>
#include "common.h"
#include "rmaset.h"
#include "constants.h"

using namespace std;

void rmaset()
{
	int seed1 = 1, seed2 = 0;
	int value1 = seed1 + 1801;
	int value2 = seed2 + 9373;
	if( value1 < 0 || value2 < 0 || value1 > 31328 || value2 > 30081){
		cout << "Invalid Seed Values: " << seed1 << " , " << seed2 << endl;
		//return 0;
	}
	int i = ((value1/177) % 177) + 2;
	int j = (value1 % 177) + 2;
	int k = ((value2/169) % 178) + 1;
	int m = value2 % 169;
	int n  = 0;
	// the way I'm doing loops is different then in the FORTRAN code so these
	// may be off by 1
	for(int y = 0; y < 97; y++ ){
		double S = ZERO;
		double T = HALF;
		// same with this for loop
		for(int x = 0; x < 24; x++){
			n = (((i*j) % 179) * k ) % 179;
			i = j;
			j = k;
			k = n;
			m = (53*(m+1)) % 169;
			if(((m*n) % 64) >= 32 ) S+=T;
			T = HALF * T;
		}
		// now add S to the array
	}

	//return 0;
}



