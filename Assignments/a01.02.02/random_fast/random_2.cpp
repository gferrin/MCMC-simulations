#include <iostream>
#include <iomanip>
#include "random_2.h"
#include "../../../Libs/C++/common.h"

using namespace std;

const int numberOfRandom = 100;

int main(void)
{
	cout<<setiosflags(ios::fixed)<<setprecision(17);

	//double U[97],C,CD,CM;
	//int I,J;
	struct Common block;

	rmaset(block);

	for(int i = 0; i <= numberOfRandom; i++){
		
		// if(i >= numberOfRandom - 5){
		// 	double random = ranmar(U,C,CD,CM,I,J);
		// 	cout << "\nnumber " << i << ": " << random << endl;
			
		// } else {
		// 	ranmar(U,C,CD,CM,I,J);
		// }

		cout << i+1 << ": " <<ranmar(block) << endl;

		
	}


	return 0;
}

void rmaset(Common &block){

	double ZERO = 0.0, HALF = 0.5;
	int seed1 = 1, seed2 = 0;
	int value1 = seed1 + 1801;
	int value2 = seed2 + 9373;

	block.I = ((value1/177) % 177) + 2;
	block.J = (value1 % 177) + 2;
	int K = ((value2/169) % 178) + 1;
	int M = value2 % 169;
	int N;

	for(int y = 0; y < 97; y++ ){
		double S = ZERO;
		double T = HALF;
		// same with this for loop
		for(int x = 0; x < 24; x++){
			N = (((block.I*block.J) % 179) * K ) % 179;
			block.I = block.J;
			block.J = K;
			K = N;
			M = (53*M+1) % 169;
			if(((M*N) % 64) >= 32 ) S+=T;
			T = HALF * T;
		}// end of nested for loop
		// now add S to the array
		block.U[y] = S;
	} //end of first for loop
	block.C = (362436.0/16777216.0);
	block.CD = 7654321.0/16777216.0;
	block.CM = 16777213.0/16777216.0;
	block.I = 96;
	block.J = 32;
}

double ranmar(Common &block)
{
	double UNI = block.U[block.I] - block.U[block.J];
	if(UNI < 0) { UNI++; }
	block.U[block.I] = UNI;
	block.I--;
	if( block.I < 0 ) { block.I = 96;}
	block.J--;
	if( block.J < 0 ) { block.J = 96;}
	block.C -= block.CD;
	if(block.C < 0) {
		block.C+= block.CM;
	}
	UNI -= block.C;
	if(UNI < 0) {UNI++;}

	return UNI;
}