#include <math.h>
#include <stdio.h>
#define ITMAX 100 // Maximum allowed number of iterations.
#define EPS 3.0e-7 // Relative accuracy.
#define FPMIN 1.0e-30 // Number near the smallest representable


void gcf(float *gammcf, float a, float x, float *gln);
// ﬂoating-point number.
// Returns the incomplete gamma function Q(a, x) evaluated by its continued fraction 
// representation as gammcf. Also returns ln Γ(a) as gln.
void gcf(float *gammcf, float a, float x, float *gln)
{
	float gammln(float xx);
	void nrerror(char error_text[]);
	int i;
	float an,b,c,d,del,h;
	*gln=gammln(a);
	b=x+1.0-a; // Set up for evaluating continued fraction
	           // by modiﬁed Lentz’s method (§5.2) with b_0 = 0.
	c=1.0/FPMIN;
	d=1.0/b;
	h=d;
	for (i=1;i<=ITMAX;i++) { // Iterate to convergence.
		an = -i*(i-a);
		b += 2.0;
		d=an*d+b;
		if (fabs(d) < FPMIN) d=FPMIN;
		c=b+an/c;	
		if (fabs(c) < FPMIN) c=FPMIN;
		d=1.0/d;
		del=d*c;
		h *= del;
		if (fabs(del-1.0) < EPS) break;
	}
	
	if (i > ITMAX){
		printf("a too large, ITMAX too small in gcf");
		return;
	} 
	*gammcf=exp(-x+a*log(x)-(*gln))*h; // Put factors in front.
}