#include <iostream>
#include "../C++/stmean.h"
#include "../C++/steb0.h"

using namespace std;

int main(void)
{
	cout << "Hello world" << endl;

	double array[] = {5.6,10.8,3.2,7.3};

	// double mean = stmean(array, 4);
	// cout << mean << endl;

	double error, mean, variance;
	
	steb0(array, 4, mean, variance, error);

	cout << "mean: " << mean << ", variance: " << variance << ", error: " << error << endl;	

	return 0;
}