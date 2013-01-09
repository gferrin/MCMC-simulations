#include <iostream>
#include "../C++/rmacau.h"
#include "../C++/rmaset.h"
#include "../C++/common.h"

using namespace std;

int main(void)
{	
	struct Common block;

	rmaset(block);	

	for(int i = 0; i < 100; i++){
		double twoPIrandom = rmacau(block);
		cout << twoPIrandom << endl;
	}


	return 0;
}