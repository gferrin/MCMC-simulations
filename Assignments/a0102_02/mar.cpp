#include <iostream>
#include <iomanip>
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/common_raset1.h"
#include "../../Libs/C++/rmasave.h"
#include "../../Libs/C++/rmaset.h"

using namespace std;

int main(void)
{
	const int timesCalled = 5;

	cout<<setiosflags(ios::fixed)<<setprecision(17);

	struct Common block;
	// inilize block 
	rmaset(block);

	for(int i = 1; i < timesCalled; i++){
		cout << i << ": " << ranmar(block) << endl; 
	}

	rmasave(block);
	// this makes it so the first number of the next file will be the same
	// as the last of the previouse one
	cout << "\nExtra Number: " << ranmar(block) << endl << endl; 

	return 0;
}