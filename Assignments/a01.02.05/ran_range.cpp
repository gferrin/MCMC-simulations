#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "../../Libs/C++/rmaset.h"
#include "../../Libs/C++/ranmar.h"
#include "../../Libs/C++/common_raset1.h"


int main(void)
{
	std::cout<<setiosflags(ios::fixed)<<setprecision(17);
	// this is 10^10 however we are trying to minimize CPU  time so this value is hard coded 	
	// Warning: this big number may lead to error with for loop
	// consider looking for alternatives
	int seed1 = 1, seed2 = 0, sampleSize = 100000000 /* 10000000000 */, minValueCounter = 0, maxValueCounter = 0; 
	double minValue = .5, maxValue = .5, random, tempRandom;
	struct Common block;

	stringstream dataFileStream;
	dataFileStream << "r" << seed1 << "_" << seed2 << ".d";

	string dataFileString = dataFileStream.str();

	ofstream dataFile((dataFileString).c_str());

	dataFile << '\n' << "seed1: " << seed1 << " seed2: " << seed2 << std::endl << std::endl;

	dataFile << "xiter, xr and xr at xiter+1:" << std::endl << std::endl;

	rmaset(block,seed1,seed2);

	for(int i = 0; i < sampleSize; i++){
		// get random number 
		random = ranmar(block);

		if(random < minValue){
			minValue = random;
			minValueCounter = 1;
		} else if (random > maxValue){
			maxValue = random;
			maxValueCounter = 1;
		} else if (random == minValue){
			
			tempRandom = ranmar(block);
			dataFile <<setiosflags(ios::fixed)<<setprecision(17);
			dataFile << fixed << minValueCounter << '\t' << i << '\t' << random << '\t' << tempRandom << std::endl;
			minValueCounter++;

		} else if ( random == maxValue){

			tempRandom = ranmar(block);
			dataFile <<setiosflags(ios::fixed)<<setprecision(17);
			dataFile << fixed << maxValueCounter << '\t' << i << '\t' << random << '\t' << tempRandom << std::endl;
			maxValueCounter++;
		}

		
	}

	dataFile << std::endl << fixed << "min value: " << minValue << " occurences: " << minValueCounter << std::endl
			  		              << "max value: " << maxValue << " occurences: " << maxValueCounter << std::endl;

	dataFile.close();

	return 0;
}