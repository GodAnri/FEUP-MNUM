#include <iostream>

using namespace std;

double f(double x)
{
	return pow(x, 7) + 0.5 * x - 0.5;
}

int main()
{
	int counter = 0;
	double x1 = 0, x2 = 0.8, xm = (x1*f(x2)-x2*f(x1))/(f(x2) - f(x1));
	while (abs(f(xm)) > 0.00001)
	{
		xm = (x1*f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
		cout << "Iteration " << counter << " - x1: " << x1 << "; x2: " << x2 << "; xm: " << xm << endl;
		if (f(xm)*f(x1) > 0)
			x1 = xm;
		else
			x2 = xm;
		counter++;
	}
	cout << "Final value: " << xm << endl;
	return 0;
}