#ifndef RMASAVE_H_
#define RMASAVE_H_

#include "common_raset1.h"
#include <fstream>
#include <string>

void rmasave(Common &block, std::string filename = "ranmar.txt");

void rmasave(Common &block, std::string filename )
{
	// open output stream
	std::ofstream outStream( filename.c_str() );

	outStream.precision(17);

	for(int i = 0; i < 97; i++){
		outStream << block.U[i] << ",";
	}
	outStream << block.I << "," << block.J << "," << block.C << ","
			  << block.CD << "," << block.CM;

	outStream.close();
}

#endif /* RMASAVE_H_ */