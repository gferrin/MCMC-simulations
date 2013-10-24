#ifndef STEB1_H_
#define STEB1_H_

#include <math.h>

void steb1(double x[], double w[], int size, double & xmean, double & xerror);

void steb1(double x[], double w[], int size, double & xmean, double & xerror)
{
	double wnorm = 0.0;

	// NORMALIZATION OF WEIGHT FACTORS:
	for(int i = 0; i < size; ++i){
		wnorm += w[i];
	}

	for(int i = 0; i < size; ++i){
		w[i] /= wnorm;
	}

	// WEIGHTED MEAN VALUE:
	xmean = 0.0;

	for(int i = 0; i < size; ++i){
		xmean += w[i] * x[i];
	}

	// UNBIASED ESTIMATOR FOR XE**2 (VARIANCE OF THE MEAN):
	double xvariance = 0.0;

	for(int i = 0; i < size; ++i){
		xvariance += w[i] * ((x[i] - xmean) * (x[i] - xmean));
	}

	xerror = sqrt(xvariance / ((size - 1) * 1.0));
}


#endif 