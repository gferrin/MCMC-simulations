#ifndef GAMMA_LN_H_
#define GAMMA_LN_H_

#include <cmath>
#include "constants.h"

double gamma_ln( const double X );

double gamma_ln( const double X )
{
	double Y, ser, serTemp, gamma;

	if( X <= 0 ) {
		std::cout << "GAMMA_LN: Argument X = " << X << std::endl
				  << "GAMMA_LN: illegal argument." << std::endl;
		return 0;
	}
	if( X > 1 ) { // Full accuracy of Lanczos formula.
		Y = X;
	} else { //Use Gamma(z+1)=z*Gamma(z).
		Y = X + 1;
	}
	serTemp = ((ONE + C1_L / Y) + C2_L / (Y + ONE)) + C3_L / (Y + TWO);
	ser = ((serTemp + C4_L / (Y + THREE)) + C5_L / (Y + FOUR)) + C6_L / (Y + FIVE);
	gamma = (Y - HALF) * log(Y + FNINE_HALF) - (Y + FNINE_HALF) + log(STP_L * ser);
	if(X > 1){ return gamma; }
	gamma -= log(X);

	return gamma;
}

#endif /* GAMMA_LN_H_ */
