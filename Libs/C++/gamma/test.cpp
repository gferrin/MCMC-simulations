#include <iostream> 
#include <boost/math/special_functions/gamma.hpp>

using namespace std;


int main(void)
{
	using namespace boost::math;

	double b = 2, c = 3, something;
	something = gamma_p(b, c);

	cout << something << endl;

	return 0;
}