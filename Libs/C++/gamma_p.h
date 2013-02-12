/* WARNING: This function has not yet been properly tested */

#ifndef GAMMA_P_H_
#define GAMMA_P_H_

#include <math.h>
#include "gamma_ln.h"
#include "constants.h"


double gamma_p( const double A, const double X );

double gamma_p( const double A, const double X )
{
	bool lfinal = false ;
	double gln, gamma_p = ZERO, sum, add, iter_max = 3800, eps = 0.000000003 , g = ZERO, a0, a1, b0, b1, gold, xiter ; // EPS = 3*10^-9

	if( X < 0 || A <= 0 ) { 
		std::cout << "A: " << A << " X: " << X << std::endl << " GAMMA_P - INPUT NOT COVERED\n" << std::endl;
		return gamma_p;
	} 

	gln = gamma_ln( A );

	if( X < (A + ONE ) ){ // series expansion:
		if( X <= ZERO ) { std::cout << "line 26 returning 0 \n"; return gamma_p; }
		sum = ONE / A ; 
		add = sum ;

		for( int i = 1; i <= iter_max; i++ ){
			add = add * X / ( A + i ) ;
			sum += add ;

			if( abs( add ) < ( abs( sum ) * eps ) ){
				gamma_p = sum * exp( -1 * X + A * log( X ) - gln );
				return gamma_p;
			}
		}
		lfinal = true ; 
	} else { // continued fraction expansion:
		a0 = X + ONE - A ;
     	b0 = ONE ;
     	a1 = X * a0 + X ;
      	b1 = X * b0 + ONE ;
      	for( int i = 2; i <= iter_max; i++ ){
      		gold = g ;
        	i *= ONE ; 
       		xiter = i - A ;
        	a0 = ( a1 + a0 * xiter ) / a1 ;
        	b0 = ( b1 + b0 * xiter ) / a1 ;
        	b1 = X * b0 + i * b1 / a1 ;
        	a1 = X * a0 + i ;
        	if( a1 == 0 ) {
        		std::cout << "a1 zero in gamma_p\n" ;
        		return gamma_p;
        	}
        	g = b1 / a1 ;
        	if( abs( ( g - gold ) / g ) < eps ) {
        		gamma_p = ONE - exp(-1 * X + A * log( X ) - gln ) * g ; // and take its complement
        		return gamma_p ;
        	}
      	}
	}

	if( ! lfinal ){
		gamma_p = ZERO;
		if( X <= ZERO ) { std::cout << "line 67 returning 0 \n"; return gamma_p; }
		sum = ONE / A ; 
		add = sum ;

		for( int i = 1; i <= iter_max; i++ ){
			add = add * X / ( A + i ) ;
			sum += add ;

			if( abs( add ) < ( abs( sum ) * eps ) ){
				gamma_p = sum * exp( -1 * X + A * log( X ) - gln ) ;
				return gamma_p;
			}
		}
	} else {
		// If this point is reached then everything has failed
		std::cout << "gamma_i: : a too large, iter_max too small\n" ;
		return gamma_p ;
	}
}

#endif /* GAMMa_P_H_ */
