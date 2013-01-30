#include <iostream>
#include <cmath>
#include <iomanip>
#include "../../Libs/C++/error_f.h"
#include "../../Libs/C++/constants.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 6, x, NA[n];
	double P[n], Q[n];

	for( int i = 0; i < n; i++ ){
		NA[i] = i + 1;
		x = ( i * ONE ) / sqrt( TWO );
		P[i] = error_f( x );
		Q[i] = HALF * ( ONE - P[i] );
	} 

	cout << "n";
	for( int j = 0; j < n; j++ ){
		cout << setw(10) << NA[j];
	}
	cout << endl << "p";
	for( int j = 0; j < n; j++ ){
		cout << setw(10) << P[j];
	}
	cout << endl << "q";
	for( int j = 0; j < n; j++ ){
		cout << setw(10) << Q[j];
	}
	cout << endl;

	return 0;
}