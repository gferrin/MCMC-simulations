#ifndef ERROR_F_H_
#define ERROR_F_H_

#include <cmath>
#include "gamma_p.h"

double error_f( double X );

double error_f( double X )
{
	double error = sin(X) * gamma_p( 0.5, ( X * X )); // Incomplete gamma function.
}

#endif /* ERROR_F_H_ */
