#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "../../Libs/C++/gau_df.h"
#include "../../Libs/C++/cau_df.h"
#include "../../Libs/C++/constants.h"

using namespace std;

int main(void)
{
	int range = 30;
	int precision = 7;

	/* probability densities: */
	ofstream prob_dens("fig1.d");
	prob_dens.precision(precision);
	prob_dens.setf(ios::left);
	
	for(int i = -range; i <= range; ++i){
	
		double x = (i * ONE) / TEN;
		double yu = ZERO;
		if( x >= -ONE && x <= ONE ){
			yu = HALF;
		}
		double yg = exp( -HALF * x * x ) / sqrt(TPI);
		double yc = ONE / (PI + (PI * x * x));
		if(x == -ONE){
			prob_dens << fixed << x << "\t" << ZERO << "\t" << scientific << yg << "\t" << yc << endl;	
		}
		prob_dens << fixed << x << "\t" << ZERO << "\t" << scientific << yg << "\t" << yc << endl;
		if(x == ONE){
			prob_dens << fixed << x << "\t" << ZERO << "\t" << scientific << yg << "\t" << yc << endl;
		}
	}
	prob_dens.close();

	/* cumulative distribution functions: */
	ofstream cum_dis("fig2.d");
	cum_dis.precision(precision);
	cum_dis.setf(ios::left);
	
	for(int i = -range; i <= range; ++i){
		
		double x = (i * ONE) / TEN;
		double yu = ZERO;
		if( x > -ONE ){
			yu = HALF * (x + ONE); 
		}
		if( x > ONE ){
			yu = ONE;
		}
		double yg = gau_df(x);
		double yc = cau_df(x);

		cum_dis << fixed << x << "\t" << scientific << yu << "\t" << yg << "\t" << yc << endl;
	}
	cum_dis.close();

	return 0;
}
