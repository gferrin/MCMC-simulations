#include <iostream>
#include "../../Libs/C++/hist_gnu.h"
#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/common_raset1.h"

using namespace std;

int main(void)
{
	int IOU = 6, IUD = 10, MIUD = (-1 * IUD), Seed1 = 1, Seed2 = 0;
	int numHist = 10, numData = 10000, N1 = 100, N2 = numData;
	double hist[numHist], data[numData], Xmin = 0.000000, Xmax = 1.000000;

	cout << "\nProgram Histogram (hist.f):\n";

	struct Common block;

	rmaset(block, Seed1, Seed2);

	for(int i = 0; i < N1; i++){
		data[i] = ranmar(block);
	}
	hist_gnu(MIUD, numHist, N1, hist, data, Xmin, Xmax);
	
	for(int i = 0; i < N2; i++){
		data[i] = ranmar(block);
	}
	hist_gnu(MIUD, numHist, N2, hist, data, Xmin, Xmax, 1);

	return 0;

}