#include <iostream>

using namespace std;

double f(double x, double y)
{
	return x * x - y - 1.2;
}

double dfx(double x, double y)
{
	return 2 * x;
}

double dfy(double x, double y)
{
	return -1;
}

double g(double x, double y)
{
	return - x + y * y - 1;
}

double dgx(double x, double y)
{
	return -1;
}

double dgy(double x, double y)
{
	return 2 * y;
}

int main()
{
	double x = 1, y = 1, x0 = 1, y0 = 1;
	for (int i = 0; i < 2; i++)
	{
		x0 = x;
		y0 = y;
		x = x0 - (f(x0, y0)*dgy(x0, y0) - g(x0, y0)*dfy(x0, y0)) / (dfx(x0, y0)*dgy(x0, y0) - dgx(x0, y0)*dfy(x0, y0));
		y = y0 - (g(x0, y0)*dfx(x0, y0) - f(x0, y0)*dgx(x0, y0)) / (dfx(x0, y0)*dgy(x0, y0) - dgx(x0, y0)*dfy(x0, y0));
		cout << "x: " << x << "; y: " << y << endl;
	}
	return 0;
}