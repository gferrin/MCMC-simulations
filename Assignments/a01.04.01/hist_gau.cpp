#include <iostream>
#include "../../Libs/C++/constants.h"
#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/rmagau.h"
#include "../../Libs/C++/hist_gnu.h"

using namespace std;

int main()
{
	double xg, yg, iud = -10;
	int nhist = 30, ndata = 10000, ndh = ndata / 2, even, odd;
	double xmin = -THREE, xmax = THREE; 
	double hist[ nhist ], data[ ndata ];

	cout << "program hist_gau (hist_gau.cpp):\n" << endl;

	struct Common block;
	rmaset( block );

	for( int i = 0; i < ndh; ++i ){
		rmagau( block, xg, yg );
		
		even = 2 * i;
		odd = even + 1;

		data[ even ] = xg;
		data[ odd ] = yg;
	}

	cout << data[ ndata - 2 ] << " " << data[ ndata - 1 ] << endl;

	hist_gnu( iud, nhist, ndata, hist, data, xmin, xmax); 

	return 0;
}