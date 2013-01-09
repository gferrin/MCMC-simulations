/*
 * common.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: Gabriel Ferrin
 */

#include "common.h"

Common::Common(){

}
void Common::Set_U(int place, double value){
	U[place] = value;
}
void Common::Set_C(double value){
	C = value;
}
void Common::Set_CD(double value){
	CD = value;
}
void Common::Set_CM(double value){
	CM = value;
}
double Common::Get_U(int place){
	double value = U[place];
	return value;
}
double Common::Get_C(){
	return C;
}
double Common::Get_CD(){
	return CD;
}
double Common::Get_CM(){
	return CM;
}
int Common::Get_I(){
	return I;
}
int Common::Get_J(){
	return J;
}


