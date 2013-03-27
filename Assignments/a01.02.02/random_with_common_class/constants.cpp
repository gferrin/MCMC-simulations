/*
 * constants.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: Gabriel
 */

#include <iostream>
#include <cmath>
#include "constants.h"

using namespace std;

	int IZERO=0,IONE=1,MIONE=-1,ITWO=2,ITHREE=3,IFOUR=4,IFIVE=5;
	double ONE=1.00,TWO=2.00,THREE=3.00,FOUR=4.00,FIVE=5.00,SIX=6.00,SEVEN=7.00,EIGHT=8.00,FNINE=9.00,TEN=10.00;
	double ONEM=-1.00,TWOM=-2.00,FOURM=-4.00;
	double ZERO=0.00,HALF=0.50,FNINE_HALF=4.50;
	double P025=0.025,P05=0.05,P15=0.15,P25=0.25,P75=0.75,P85=0.85,P95=0.95,P975=0.975;
	double EM3=1.0e-3,EM4=1.0e-4,EM5=1.0e-5,EM6=1.0e-6,EM7=1.0e-7,EM8=1.0e-8,EM9=1.0e-9,EM10=1.0e-10,EM11=1.0e-11,EM12=1.0e-12;
	double PI=3.1415926535897931159979634685441852,TPI=6.2831853071795862319959269370883703;
// Half of Marsaglia random number discretization:
	double EPSMAR = pow(2.0,-25); // 2 ^ -25
// Lancos coefficients for GAMMA_LN:
	double C1_L=76.18009173,C2_L=-86.50532033,C3_L=24.01409822;
	double C4_L=-1.231739516,C5_L=0.120858003,C6_L=-.536382e-5; // this may be wrong there is D-5 after number in FORTRAN code
	double STP_L=2.50662827465,hbar=4.135669e-15;

