#ifndef HIST_GNU_H_
#define HIST_GNU_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include "razero.h"

using namespace std;

void hist_gnu(int IUG0, int numberHist, int numberData, double histagram[], double Data[], double xMin, double xMax, int timesCalled = 0 );

void hist_gnu(int IUG0, int numberHist, int numberData, double histagram[], double Data[], double xMin, double xMax, int timesCalled )
{
	int number_omit = 0;
	const int precision = 7;
	const double zero = 0.000000;

	timesCalled++;

	if( timesCalled > 99){
		cout << "HIST_GNU: INCT=99 Exhausted!" << endl;
		return;
	}
	// this is an array which will always have digits in it and will represent the file number 
	// based on the number of times HIST_GNU was called by a given rutine 
	int fileNumber[] = { (timesCalled - ( timesCalled % 10 )) / 10 , (timesCalled % 10 )};

	int IUG = fabs(IUG0);
	// create nessissary file streams
	stringstream hDataStream, hPlotStream, iDataStream, iPlotStream;
	hDataStream << "h" << fileNumber[0] << fileNumber[1] << ".d";
	hPlotStream << "h" << fileNumber[0] << fileNumber[1] << ".plt";    
	iDataStream << "i" << fileNumber[0] << fileNumber[1] << ".d";
	iPlotStream << "i" << fileNumber[0] << fileNumber[1] << ".plt"; 
	// convert them to strings
	string hData = hDataStream.str(), hPlot = hPlotStream.str(), iData = iDataStream.str(), iPlot = iPlotStream.str();   
	string totalPlot = "hist.plt";
	// open file 
	cout << "HIST_GNU: Open files " << hPlot << " and " << hData << endl;
	
	ofstream histPlotOutStream((hPlot).c_str());

	histPlotOutStream << "plot \"" << hData << "\" using 1:2 with line lt 1\npause -1\n";
	histPlotOutStream.close();

	cout << "HIST_GNU: Open files " << iPlot << " and " << iData << endl; 	
	
	ofstream iPlotOutStream((iPlot).c_str());
	iPlotOutStream << "plot \"" << iData << "\" using 1:2 with impulses\npause -1\n";
	iPlotOutStream.close();

	if( timesCalled > 1 ){
		cout << "HIST_GNU: Open file his.plt to plot all histograms." << endl;
		ofstream totalPlotStream((totalPlot).c_str());
		totalPlotStream << "plot \"h01.d\" using 1:2 with line lt 1,\\" << endl;

		for(int i = 2; i < timesCalled; i++){
			int tempFileNumber[] = { (i - ( i % 10 )) / 10 , ( i % 10 )};
			totalPlotStream << "\t\"h" << tempFileNumber[0] << tempFileNumber[1] <<".d\""
							<< " using 1:2 with line lt " << i << ",\\" << endl; 
		}
		totalPlotStream << "\t \"" << hData << "\" using 1:2 with line lt " << timesCalled << "\npause -1\n";

		totalPlotStream.close();
	}
	// set histogram array to zero
	razero(histagram, numberHist);

	if( xMax < xMin){
		xMin = Data[0];
		xMax = Data[0];
		for(int i = 1; i < numberData; i++){
			if( xMin > Data[i]){
				xMin = Data[i];
			} else if( xMax < Data[i]){
				xMax = Data[i];
			}
		}
		xMin -= ((xMax-xMin)/10000)/numberHist;
		xMax += ((xMax-xMin)/10000)/numberHist;
	}
	cout << "HIST_GNU: xMin = " << xMin << ", xMax = " << xMax << endl << endl; 

	double factor = (numberHist * 1.00000)/(xMax - xMin);
	double xData = zero, X;
	int intX;
	for(int i = 0; i < numberData; i++){
		X = .5 + factor * (Data[i] - xMin);
		intX = round(X) - 1;
		if( intX < 0 || intX >= numberHist){ 
			number_omit++;
		} else {
			histagram[intX] = histagram[intX] + 1;
			xData++;
		}
 	}

	double delta = (xMax - xMin)/(numberHist * 1.00000);
	

	ofstream hDataOutStream((hData).c_str());

	hDataOutStream.precision(precision);
	hDataOutStream.setf(ios::left);
	
	X = xMin;
	if( IUG0 < 0 ){
		factor = 1.00000/xData/delta;
		histagram[0] = histagram[0] * factor;
	}
	hDataOutStream << fixed << X << '\t' << zero << endl;
	hDataOutStream << X << '\t' << histagram[0] << endl;

	for(int j = 0; j < numberHist - 1; j++){
		if(IUG0 < 0){
			histagram[j + 1] = factor * histagram[j + 1];
		}
		X += delta;
		hDataOutStream << X << '\t' << histagram[j] << endl;
		if( IUG == 8 ) { hDataOutStream << X << '\t' << zero << endl; }
		hDataOutStream << X << '\t' << histagram[j+1] << endl;
	}

	X += delta;
	hDataOutStream << X << '\t' << histagram[numberHist-1] << endl;
	hDataOutStream << X << '\t' << zero << endl;

	hDataOutStream.close();

	ofstream iDataOutStream((iData).c_str());
	// re-set X and offset it by delta/2 so it graphs properly
	X = xMin - (delta/2);
	for( int k = 0; k < numberHist; k++){
		X += delta;
		iDataOutStream << fixed << X << '\t' << histagram[k] << endl;
	}

	iDataOutStream.close();

	if(number_omit > 0){
		cout << "HIST_GNU Warning: Data omitted\n" << endl; 
	}

	return;
}

#endif /* HIST_GNU_H_ */