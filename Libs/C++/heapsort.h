#ifndef _HEAPSORT_
#define _HEAPSORT_

void Heapsort(double arrayToSort[], int sizeOfArray);

void Heapsort(double arrayToSort[], int sizeOfArray)
{

	//      Building Heap:
	// ==========================

	int halfSize = (sizeOfArray-1) / 2;

	for(int i = halfSize; i >= 0; i--){
		double temp = arrayToSort[i];
		int I1 = i, I2 = i+i;
		do {
			if( I2 < sizeOfArray - 1 && arrayToSort[I2+1] > arrayToSort[I2] ) { I2++; }
			if( arrayToSort[I2] > temp ){
				arrayToSort[I1] = arrayToSort[I2];
				I1 = I2;
				I2 = I1+I1;
			} else {
				I2 = sizeOfArray;
			}
		} while ( I2 < sizeOfArray );
		arrayToSort[I1] = temp;
	}

	//      Sorting Heap:
	// =========================

	for(int i = sizeOfArray-1; i >= 2; i--){ // i is the number of still competing elements
		double temp = arrayToSort[i];
		arrayToSort[i] = arrayToSort[0]; // store top of the heap
		int I1 = 0, I2 = 1;
		do {
			if((I2+1) < i && arrayToSort[I2+1] > arrayToSort[I2] ) { I2++; }
			if(arrayToSort[I2] > temp ){
				arrayToSort[I1] = arrayToSort[I2];
				I1 = I2;
				I2 = I1+I1;
			} else {
				I2 = i;
			}
		} while( I2 < i );
		arrayToSort[I1] = temp;

	}

	double Temp = arrayToSort[1];
	arrayToSort[1] = arrayToSort[0];
	arrayToSort[0] = Temp;
}

#endif /* _HEAPSORT_ */