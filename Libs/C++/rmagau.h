#ifndef RMAGAU_H_
#define RMAGAU_H_

#include <math.h>
#include "ranmar.h"
#include "common_raset1.h"

#define PI 3.14159265

void rmagau(Common &block, double &sinRan, double &cosRan);

void rmagau(Common &block, double &sinRan, double &cosRan)
{
	double twoPI = 2*PI, R;
	double random = ranmar(block);

	R = sqrt(fabs(2.0 * log(1.0 - random)));

	sinRan = R * sin(twoPI * random);
	cosRan = R * cos(twoPI * random);
}

#endif /* RMAGAU_H_ */