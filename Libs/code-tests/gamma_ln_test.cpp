#include <iostream>
#include "../C++/gamma_ln.h"

using namespace std;

int main(void)
{
	for(double i = 0; i < 10; ++i ){
		cout << i << ": " << gamma_ln(i) << endl; 
	}

	return 0;
}