#include <iostream>
#include <cmath>

#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/rmagau.h"
#include "../../Libs/C++/rmacau.h"
#include "../../Libs/C++/steb0.h"
#include "../../Libs/C++/common_raset1.h"

using namespace std;

int main(void)
{
	int ndat = pow(2.0, 10.0), nda2 = 2 * ndat;
	double data[nda2];
	double mean, variance, error;

	struct Common block;
	rmaset(block);

	cout << "\nProgram EB0 (eb0.f):" << endl;
	cout << "NDAT = " << ndat << endl << endl;

	for(int i = 0; i < 3; ++i){
		for(int n = 0; n < ndat; ++n){
			
			if(i == 0){
				data[n] = ranmar(block);
			} 
			else if(i == 1){
				rmagau(block, data[n], data[ndat + n]);
			} 
			else if(i == 2){
				data[n] = rmacau(block);
			}
		}

		if(i != 1){
			steb0(data, ndat, mean, variance, error);
		} else {
			steb0(data, nda2, mean, variance, error);
		}

		if(i == 0) cout << "UNIFORM  RANDOM NUMBERS:" << endl;
		else if(i == 1) cout << "GAUSSIAN RANDOM NUMBERS:" << endl;
		else if(i == 2) cout << "CAUCHY   RANDOM NUMBERS:" << endl;

		cout << "xmean = " << mean << "  +/-  " << error << endl; 
	}

	cout << "\n";

	return 0;
}