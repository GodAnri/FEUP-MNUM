#include <iostream>

using namespace std;

int main()
{
	double x0 = 0, y0 = 0, z0 = 0, t0 = 0;
	double x = (2.5 - 0.5*y0 - 3 * z0 - 0.25*t0)/6;
	double y = (3.8 - 1.2*x - 0.25 * z0 - 0.2*t0)/3;
	double z = (10 + x - 0.25 * y - 2*t0)/4;
	double t = (7 - 2*x - 4 * y - z)/8;
	cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << "t: " << t << endl;
	return 0;
}