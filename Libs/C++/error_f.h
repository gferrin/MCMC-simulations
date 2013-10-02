#ifndef ERROR_F_H_
#define ERROR_F_H_

#include <cmath>
// #include <boost/math/special_functions/gamma.hpp>
#include "constants.h"
#include "gamma_i.h"

// using namespace boost::math;

double error_f( double X );

double error_f( double X )
{
	double sign = 1;

	if(sin(X) < 0){
		sign *= -1;
	}

	double error = sign * gamma_i(0.5, ( X * X )); // Incomplete gamma function.
	// std::cout << "sin(x): " <<  sin(X) << " gamma_i: " << gamma_i( HALF, ( X * X )) << std::endl;
	return error;
}

#endif /* ERROR_F_H_ */
