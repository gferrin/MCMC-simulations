#ifndef GAU_XQ_H_
#define GAU_XQ_H_

#include "gau_df.h"
#include "constants.h"
#include "function_inverse1.h"

double gau_xq(double q);

double gau_xq(double q)
{
	double gau_xp;
	double x1 = ZERO, x2 = ZERO;

	if(q == HALF){
		return ZERO;
	}
	if(q > HALF){
		do{
			x2 += ONE;
		} while(gau_df(x2) <= q);
	} else{
		do{
			x1 -= ONE;
		} while(gau_df(x1) >= q);
	}
	return function_inverse1(gau_df, q, x1, x2);
}

#endif /* GAU_XQ_H_ */