#include <iostream>

using namespace std;

double f(double x)
{
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

int main()
{
	double a = 1.5, b = 4.2, m;
	for (int i = 0; i < 2; i++)
	{
		m = (a + b) / 2.0;
		if (f(a)*f(m) > 0)
			a = m;
		else
			b = m;
	}
	cout << "b: " << b;
	return 0;
}