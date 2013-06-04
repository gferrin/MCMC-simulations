#ifndef GAU_DF_H_
#define GAU_DF_H_

#include <math.h>
#include "error_f.h"
#include "constants.h"

double gau_df( double x );

double gau_df( double x )
{
	double xx = x / sqrt(TWO);
	return HALF + HALF * error_f(xx);
}

#endif /* GAU_DF_H_ */