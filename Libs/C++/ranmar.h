#ifndef RANMAR_H_
#define RANMAR_H_

#include "common_raset1.h"

double ranmar(Common &block);

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

#endif /* RANMAR_H_ */
