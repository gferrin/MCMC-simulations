#ifndef ERROR_F_H_
#define ERROR_F_H_

#include <cmath>
#include "gamma_p.h"
#include "constants.h"

double error_f( double X );

double error_f( double X )
{
	double error = sin(X) * gamma_p( HALF, ( X * X )); // Incomplete gamma function.
}

#endif /* ERROR_F_H_ */
