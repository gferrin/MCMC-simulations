/*
 * common.h
 *
 *  Created on: Sep 6, 2012
 *      Author: Gabriel Ferrin
 */

#ifndef COMMON_H_
#define COMMON_H_

class Common {
public:
	Common();
	void Set_U(int place, double value);
	void Set_C(double value);
	void Set_CD(double value);
	void Set_CM(double value);
	void Set_I(int value);
	void Set_J(int value);
	double Get_U(int place);
	double Get_C();
	double Get_CD();
	double Get_CM();
	int Get_I();
	int Get_J();
private:
	double U[97];
	double C,CD,CM;
	int I,J;
};



#endif /* COMMON_H_ */
