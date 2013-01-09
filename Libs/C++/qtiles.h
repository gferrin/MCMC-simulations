#ifndef QTILES_H_
#define QTILES_H_

void qtiles(double array[], int arraySize, double Q, int &XQ1, int &XQ2);

void qtiles(double array[], int arraySize, double Q, int &XQ1, int &XQ2)
{
	int NQ;
	double W1, W2; 

	NQ = (int)(arraySize * Q);

	if(NQ == 0) {
		std::cout << 'QTILES: N too small.\n';
		return 0; 
	}

	W2 = Q*(N+1)-(NQ*ONE);
	W1 = ONE-W2;
	XQ1 = W1 * X (NQ) + W2 * X (NQ+1);
    XQ2 = W1 * X (N+1-NQ) + W2 * X (N-NQ);
}

#endif /* QTILES_H_ */