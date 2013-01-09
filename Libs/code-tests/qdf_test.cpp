#include <iostream>
#include "qdf_gnu.h"
#include "heapsort.h"
#include "rmaset.h"
#include "ranmar.h"
#include "common.h"


using namespace std;

int main(void)
{
	const int size = 10000;
	struct Common block;

	rmaset(block);

	double array[size], array2[size], array3[size];

	for(int i = 0; i < 3*size; i++){
		if(i < size) {
			array[i] = ranmar(block);
		} else if ( i < 2*size){
			array2[i] = ranmar(block);
		} else {
			array3[i] = ranmar(block);
		}
	

	}
	// sort all of the arrays
	Heapsort(array,size);
	Heapsort(array2,size);
	Heapsort(array3,size);
	
	qdf_gnu(array,size,0);
	qdf_gnu(array2,size,1);
	qdf_gnu(array,size,2);


	return 0;
}