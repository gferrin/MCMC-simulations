#include <iostream>
#include <iomanip> 
#include <cmath>

#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/steb1.h"
#include "../../Libs/C++/common_raset1.h"

using namespace std;

int main(void)
{
	int kmax = 10;
	double data[kmax], weight[kmax];
	double mean, error;

	cout <<  "Program EB1 (eb1.cpp):" << endl;

	struct Common block;
	rmaset(block, 1, 0, string("rmarin.d"));

	double dat = 0.0;
	for(int k = 1; k <= kmax; ++k){

		double ndat = pow(2.0, k);
		
		if(k == kmax) ndat = 2;
		dat += ndat;

		data[k - 1] = 0.0;
		for(int n = 0; n < ndat; ++n){
			data[k - 1] += ranmar(block);
		}

		weight[k - 1] = ndat;
		data[k - 1] /= ndat;

		cout << "K, NDAT, DATA(K): " << setw(4) << k << setw(7) << ndat << " " << setw(10) << (data[k - 1]) << endl; 
	}

	steb1(data, weight, kmax, mean, error);

	cout << "UNIFORM RANDOM NUMBERS: xmean = " << mean << "  +/-  " << error << endl; 

	return 0;
}