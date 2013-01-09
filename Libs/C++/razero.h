#ifndef RAZERO_H_
#define RAZERO_H_

// finalN should never be larger then the total size of array
void razero(double array[], int finalN, int intitalN = 0);

void razero(double array[], int finalN, int intitalN)
{
	double zero = 0.000000;
	for(int i = intitalN; i < finalN; i++){
		array[i] = zero;
	}
} 

#endif /* RAZERO_H_ */