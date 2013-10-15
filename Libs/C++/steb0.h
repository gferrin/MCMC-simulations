#ifndef STEB0_H_
#define STEB0_H_

#include <math.h>

void steb0(double array[], int array_size, double & xmean, double & xvariance, double & xerror);

void steb0(double array[], int array_size, double & xmean, double & xvariance, double & xerror)
{
	if(array_size < 2){ return; }

	// Mean Value
	xmean = 0;
	for(int i = 0; i < array_size; i++){

		xmean += array[i];
	}
	xmean /= array_size; 

	// ESTIMATOR FOR THE VARIANCE:
	xvariance = 0;
	for(int i = 0; i < array_size; i++){

		double quantity = (array[i] - xmean);
		xvariance += (quantity * quantity);
	}
	xvariance = xvariance / (array_size - 1);

	// ERROR BAR:
	xerror = sqrt(xvariance / (array_size * 1.0));
}


#endif 