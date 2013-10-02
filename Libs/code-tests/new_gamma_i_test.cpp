#include <iostream>
#include "../C++/new_gamma_i.h"

using namespace std;

int main(void)
{

	cout << "Hello World" << endl;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			cout << gamma_i(i, j) << endl;
		}
	}

	return 0;
}