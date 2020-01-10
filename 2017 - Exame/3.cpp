#include <iostream>

using namespace std;

double f(double x)
{
	return exp(x) - x - 5;
}

double df(double x)
{
	return exp(x) - 1;
}

double g(double x)
{
	return log(5 + x);
}

int main()
{
	double x = 2, xprev = 100;
	int counter = 0;
	while (abs(x - xprev) > 0.00001)
	{
		counter++;
		xprev = x;
		x = x - f(x) / df(x);
	}
	cout << "NEWTON - Number of iterations: " << counter << "; x = " << x << endl;
	x = 2;
	xprev = 100;
	counter = 0;
	while (abs(x - xprev) > 0.00001)
	{
		counter++;
		xprev = x;
		x = g(x);
	}
	cout << "PICARD-PEANO - Number of iterations: " << counter << "; x = " << x;
	return 0;
}