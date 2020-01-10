#include <iostream>

using namespace std;

double w(double x, double y)
{
	return -1.1 * x * y + 12 * y + 7 * x * x - 8 * x;
}

double dwx(double x, double y)
{
	return -1.1 * y + 14 * x - 8;
}

double dwy(double x, double y)
{
	return -1.1 * x + 12;
}

int main()
{
	double x0 = 3, y0 = 1, lambda = 0.1;
	double x = x0 - lambda * dwx(x0, y0);
	double y = y0 - lambda * dwy(x0, y0);
	cout << "x: " << x << "; y: " << y << "; w(x,y): " << w(x,y);
	return 0;
}