#ifndef RMACAU_H_
#define RMACAU_H_

#include <math.h>
#include "ranmar.h"
#include "common_raset1.h"

#define PI 3.14159265

double rmacau(Common &block);

double rmacau(Common &block)
{
	double twoPI = 2*PI, result;
	double random = ranmar(block);

	result = tan(twoPI * random);

	return result;
}

#endif /* RMACAU_H_ */