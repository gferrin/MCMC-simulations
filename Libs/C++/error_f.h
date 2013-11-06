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

	if( X < 0){
		sign *= -1;
	}

	double error = sign * gamma_i(0.5, ( X * X )); // Incomplete gamma function.
	return error;
}

#endif /* ERROR_F_H_ */
