#include <iostream>

using namespace std;

double f(double x)
{
	return pow(x - 8, 2) + pow(x, 4);
}

int main()
{
	double a = 1, b = 3, phi = (sqrt(5) - 1) / 2, result;
	double x1 = a + (b - a)*pow(phi,2), x2 = a + (b - a)*phi;
	int counter = 0;
	while (b - a > 0.001)
	{
		counter++;
		if (f(x1) < f(x2))
		{
			b = x2;
			x2 = x1;
			x1 = a + (b - a)*pow(phi, 2);
			result = (x1 + x2)/2;
		}
		else
		{
			a = x1;
			x1 = x2;
			x2 = a + (b - a)*phi;
			result = (x1 + x2) / 2;
		}
		cout << "Iteracao " << counter << ": a = " << a << "; b = " << b << endl;
	}
	cout << "Final value: " << result;
	
	return 0;
}