#ifndef STMEAN_H_
#define STMEAN_H_

double stmean(double array[], int size);

double stmean(double array[], int size){

	double xm = 0;

	for(int i = 0; i < size; i++){
		xm += array[i];
	}

	return (xm/size);
}

#endif 