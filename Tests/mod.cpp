/*
 * mod.cpp
 *
 *  Created on: Sep 4, 2012
 *      Author: Gabriel Ferrin
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{

	cout << "\n Test discrete mod function:\n" << endl;
	for(int i = 0; i < 5; i++){
		int x = i % 2;
		int y = (-1*i) % 2;
		cout << " i: " << i << " i mod 2: " << x << " -i: " << setw(2) << (-1*i) << " -i mod 2: "
			 << setw(2) << y << endl;
	}
	return 0;
}


