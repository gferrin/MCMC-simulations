#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "../../Libs/C++/gau_df.h"
#include "../../Libs/C++/error_f.h"
#include "../../Libs/C++/gamma_i.h"
#include "../../Libs/C++/gamma_ln.h"
#include "../../Libs/C++/cau_df.h"
#include "../../Libs/C++/constants.h"

using namespace std;

// ANALYTICAL PROBABILITY DENSITIES AND DISTRIBUTION FUNCTIONS:
// YU UNIFORM, YG GAUSS AND YC CAUCHY.

int main(void)
{
	double x, yu = 0, yg = 0, yc = 0;  

	cout << "\nProgram PDF (pdf.f):\n" << endl;

	// PROBABILITY DENSITIES:
	ofstream data_file("fig1.d");

	for(int i = -30; i <= 30; i++){
		x = (i * ONE)/TEN;
		yu = ZERO;
		if(x >= -1 && x <= 1){
			yu = HALF;
		}
		yg = exp(-HALF * x * x) /sqrt(TPI);
		yc = ONE/(PI + PI * x * x);
		if(x == -ONE){
			data_file << setw(10) << x << ZERO << yg << yc << endl;
		}
		data_file << setw(10) << x << yu << yg << yc << endl;
		if(x == ONE){
			data_file << setw(10) << x << ZERO << yg << yc << endl;
		}
	} 

	data_file.close();

	// CUMULATIVE PEAKED DISTRIBUTION FUNCTIONS:
	ofstream data_file2("fig3.d");
	
	for(int i = -30; i <= 30; i++){
		x = (i * ONE)/TEN;
		yu = ZERO;
		
		if(x > ONE){
			yu = ONE;
		} else if(x > -ONE){
			yu = HALF * (x + ONE);
		}

		yg = gau_df(x);
		yc = cau_df(x);

		if(yu > HALF) yu = ONE - yu;
		if(yg > HALF) yg = ONE - yg;
		if(yc > HALF) yc = ONE - yc;

		data_file2 << x << yu << yg << yc << endl;
	} 	

	data_file2.close();

	return 0;
}







