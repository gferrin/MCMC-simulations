/* WARNING: This function has not yet been properly tested */

#ifndef GAMMA_I_H_
#define GAMMA_I_H_

#include <math.h>
#include "gamma_ln.h"
#include "constants.h"


double gamma_i( const double A, const double X );

double gamma_i( const double A, const double X )
{
	bool lfinal = false ;
	double gln, gamma_i = ZERO, sum, add, iter_max = 3800, eps = 0.000000003 , g = ZERO, a0, a1, b0, b1, gold, xiter ; // EPS = 3*10^-9

	if( X < 0 || A <= 0 ) { 
		std::cout << "A: " << A << " X: " << X << std::endl << " gamma_i - INPUT NOT COVERED\n" << std::endl;
		return gamma_i;
	} 

	gln = gamma_ln( A );

	if( X < (A + ONE ) ){ // series expansion:
		if( X == ZERO ) { std::cout << "line 26 returning 0 \n"; return gamma_i; }
		sum = ONE / A ; 
		add = sum ;

		for( int i = 1; i <= iter_max; i++ ){
			add = add * X / ( A + i );
			sum += add;

			if( abs( add ) < ( abs( sum ) * eps ) ){
				gamma_i = sum * exp( -1 * X + A * log( X ) - gln );
				return gamma_i;
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
        		std::cout << "a1 zero in gamma_i\n" ;
        		return gamma_i;
        	}
        	g = b1 / a1 ;
        	if( abs( ( g - gold ) / g ) < eps ) {
        		gamma_i = ONE - exp(-1 * X + A * log( X ) - gln ) * g ; // and take its complement
        		return gamma_i ;
        	}
      	}
	}

	if( !lfinal ){
		gamma_i = ZERO;
		if( X <= ZERO ) { std::cout << "line 67 returning 0 \n"; return gamma_i; }
		sum = ONE / A ; 
		add = sum ;

		for( int i = 1; i <= iter_max; i++ ){
			add = add * X / ( A + i ) ;
			sum += add ;

			if( abs( add ) < ( abs( sum ) * eps ) ){
				gamma_i = sum * exp( -1 * X + A * log( X ) - gln ) ;
				return gamma_i;
			}
		}
	} else {
		// If this point is reached then everything has failed
		std::cout << "gamma_i: : a too large, iter_max too small\n" ;
		return gamma_i ;
	}
}

#endif /* GAMMa_I_H_ */
