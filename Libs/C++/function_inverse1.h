#ifndef FUNCTION_INVERSE1_H_
#define FUNCTION_INVERSE1_H_

#include <iostream>
#include <math.h>
#include "constants.h"

double function_inverse(double (*f)(double), double , double, double);

double function_inverse(double (*f)(double), double y, double x1, double x2)
{
	double eps = ONE / pow(TEN, 8.0);
	int iter_max = 1000, iter = 0;
	double xx1, xx2, y1, y2, xx, ff;

	do {
		xx1 = x1;
		xx2 = x2;
		y1 = f(xx1);
		y2 = f(xx2);

	} while(y1 > y2);

	if(y < y1 || y > y2){
		std::cout << "function_inverse1: NO CONVERGENCE OR Y OUT OF RANGE" << std::endl;
		std::cout << "iter_max: " << iter_max << ", eps: " << eps << std::endl;
		std::cout << "xx1: " << xx1 << ", xx2: " << xx2 << std::endl;
		std::cout << "y: " << y << ", y1: " << y1 << ", y2: " << y2 << std::endl;
		return 0; 
	}

	do {
		iter++;
		if(iter > iter_max){
			if(y < y1 || y > y2){
				std::cout << "function_inverse1: NO CONVERGENCE OR Y OUT OF RANGE" << std::endl;
				std::cout << "iter_max: " << iter_max << ", eps: " << eps << std::endl;
				std::cout << "xx1: " << xx1 << ", xx2: " << xx2 << std::endl;
				std::cout << "y: " << y << ", y1: " << y1 << ", y2: " << y2 << std::endl;
				return 0; 
			}
		}

		xx = HALF * (xx2 + xx1);
		ff = f(xx);
		if(ff <= y){ xx1 = xx; }
		if(ff > y){ xx2 = xx; }

	} while(abs(xx2 - xx1) > eps);

	return HALF * (xx2 + xx1);
}

#endif /* FUNCTION_INVERSE1_H_ */
