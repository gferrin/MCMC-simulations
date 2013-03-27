#include <iostream>
#include "../C++/rmaset.h"
#include "../C++/rmagau.h"
#include "../C++/rmasave.h"
#include "../C++/common_raset1.h"

using namespace std;

int main()
{
	cout << "Hello world\n";

	double sine, cosne;
	struct Common block;
	
	rmaset(block);

	rmagau(block, sine, cosne);

	//rmasave(block);

	cout << "sin: " << sine << " cos: " << cosne << endl ;	


	return 0;
}