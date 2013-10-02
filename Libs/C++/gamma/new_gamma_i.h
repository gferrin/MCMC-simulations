#ifndef GAMMA_I_H_
#define GAMMA_I_H_

#include <math.h>
#include "gamma_ln.h"
#include "constants.h"


double gamma_i(const double a, const double x);
double series_expansion(const double a, const double x, const double iter_max, const double eps, const double gln, bool &lbad1, bool &lbad2);

double gamma_i(const double a, const double x)
{
	bool lbad1 = false, lbad2 = false;
	double gamma_i = 0, sum = 0, add = 0, iter_max = 3800, eps = 0.000000003;
	double g = 0, a0 = 0, a1 = 0, b0 = 0, b1 = 0, gold = 0;
	double xiter = 0, xiterma = 0;

	if(x < 0 || a <= 0){
		std::cout << "A: " << a << " X: " << x << std::endl << " gamma_i - INPUT NOT COVERED\n" << std::endl;
		return 0;
	}

	double gln = gamma_ln(a);

	// attempt series expansion
	gamma_i = series_expansion(a, x, iter_max, eps, gln, lbad1, lbad2);

	if(lbad1){
		return 0;
	} else if(gamma_i != 0){
		return gamma_i;
	} else {
		
		// if that fails try continued fraction expansion
		g = 0;
		a0 = x + 1 - a;
		b0 = 1;
		a1 = x * a0 + x;
		b1 = x * b0 + 1;

		for(int i = 2; i <= iter_max; i++){
			gold = g;
			xiter = i * 1.0;
			xiterma = xiter - a;
			a0 = (a1 + a0 * xiterma) / a1;
			b0 = (b1 + b0 * xiterma) / a1;
			b1 = x + b0 + ((xiter * b1) / a1);
			a1 = x * a0 + xiter;

			if(a1 == 0){
				std::cout << "A1 ZERO in GAMMA_P" << std::endl;
				return 0;
			}
			g = b1 / a1;

			if(abs(g - gold) / g < eps){
				gamma_i = 1 - exp(-x + a * log(x) - gln) * g;
				return gamma_i;
			}

			if(lbad2){
				std::cout << "GAMMA_P-2: A too large, ITER_MAX too small" << std::endl;
				return 0;
			}

			lbad1 = true;

			gamma_i = series_expansion(a, x, iter_max, eps, gln, lbad1, lbad2);

			if(gamma_i != 0){
				return gamma_i;
			} else if(lbad1){
				return 0;
			}
		}		
	}
}

double series_expansion(const double a, const double x, const double iter_max, const double eps, const double gln, bool &lbad1, bool &lbad2)
{
	double gamma_i = 0, sum = 0, add = 0;

	while((x < (a + 1) && !lbad2) || lbad1){
		gamma_i = 0;
		if(x <= 0) return 0;
		sum = ONE / a;
		add = sum;

		for(int i = 1; i <= iter_max; i++){
			add *= x / (a + i);
			sum += add;

			if(abs(add) < abs(sum) * eps){
				gamma_i = sum * exp(-x + a * log(x) - gln);
				return gamma_i;
			}
		}

		if(lbad1){
			std::cout << "GAMMA_P-1: A too large, ITER_MAX too small" << std::endl;
			return 0;
		}

		lbad2 = true;
	} 

	return 0;  // to indicate that this didnt work
}

#endif /* GAMMa_I_H_ */
