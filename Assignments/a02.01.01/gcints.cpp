#include <iostream>
#include <cmath>
#include <iomanip>
#include "../../Libs/C++/error_f.h"
#include "../../Libs/C++/constants.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 6, NA[n];
	double x, P[n], Q[n];

	for( int i = 0; i < n; i++ ){
		NA[i] = i + 1;
		x = ((i + 1) * ONE) / sqrt(TWO);
		P[i] = error_f(x);
		Q[i] = HALF * (ONE - P[i]);
	} 

	// Formating

	cout << "n" << "\t";;
	for(int j = 0; j < n; j++){
		cout << NA[j] << ", ";
	}
	cout << endl << "p" << "\t";
	for(int j = 0; j < n; j++){
		cout << setprecision(2) << P[j] << ", ";
	}
	cout << endl << "q" << "\t";
	for(int j = 0; j < n; j++){
		cout  << setprecision(2) << Q[j] << ", ";
	}
	cout << endl;

	return 0;
}