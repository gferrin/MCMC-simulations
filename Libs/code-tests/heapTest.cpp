#include <iostream>
#include "heapsort.h"

using namespace std;

int main(void){
	double something[8] = {33.2,2,5.6,3.4,111,2121,1.793,7};

	Heapsort(something,8);

	for(int i = 0;i<8;i++){
		cout << something[i] << endl;
	}


	return 0;
}