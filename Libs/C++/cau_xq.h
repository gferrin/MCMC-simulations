#ifndef CAU_XQ_H_
#define CAU_XQ_H_

#include <math.h>
#include "constants.h"

double cau_xq(double q);

double cau_xq(double q)
{	
	double qq = PI * (q - HALF);
	return tan(qq);
}

#endif /* CAU_XQ_H_ */