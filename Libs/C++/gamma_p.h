#ifndef GAMMA_P_H_
#define GAMMA_P_H_


double gamma_p(double A, double X );

double gamma_p(double A, double X )
{
	bool lbad1 = false, lbad2 = false;

	if( X < 0 || A <= 0 ) { 
		std::cout << 'A:' << A << ' X: ' << X << std::endl << 'GAMMA_P - INPUT NOT COVERED\n' << std::endl;
		return 0;
	}

}

#endif /* GAMMA_P_H_ */
