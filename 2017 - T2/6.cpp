#include <iostream>

using namespace std;

double dz(double t, double z)
{
	return 2 + pow(t, 2) + t * z;
}

int main()
{
	double h = 0.25, t = 1, y = 1, z = 0, deltaz;
	cout << "EULER: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		deltaz = dz(t, z);
		t += h;
		y += h * z;
		z += h * deltaz;
	}
	cout << endl << endl << "RK4: " << endl;
	h = 0.25;
	t = 1;
	y = 1;
	z = 0;
	double z1, z2, z3, z4, dz1, dz2, dz3, dz4;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		z1 = (h * z);
		dz1 = h * dz(t, z);
		z2 = (h * (z + dz1 / 2));
		dz2 = (h * (dz(t + h/2, z + dz1 / 2)));
		z3 = (h * (z + dz2 / 2));
		dz3 = (h * (dz(t + h/2, z + dz2 / 2)));
		z4 = (h * (z + dz3));
		dz4 = (h * (dz(t + h, z + dz3)));
		y += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		t += h;
	}
}
