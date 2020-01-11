#include <iostream>

using namespace std;

double dz(double t, double y, double z)
{
	return 0.5 + t * t + t * z;
}

double dy(double t, double y, double z)
{
	return z;
}

int main()
{
	double t = 0, y = 0, z = 1, dt = 0.25, t0, y0, z0, dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;
	{
		for (int i = 0; i < 2; i++)
		{
			t0 = t;
			y0 = y;
			z0 = z;
			t = t0 + dt;
			y = y0 + dt * dy(t0, y0, z0);
			z = z0 + dt * dz(t0, y0, z0);
			cout << "t: " << t << "; y: " << y << "; z: " << z << endl;
		}
		t = 0;
		y = 0;
		z = 1;
		for (int i = 0; i < 2; i++)
		{
			t0 = t;
			y0 = y;
			z0 = z;
			dy1 = dt * dy(t0, y0, z0);
			dz1 = dt * dz(t0, y0, z0);
			dy2 = dt * dy(t0 + dt / 2, y0 + dy1 / 2, z0 + dz1 / 2);
			dz2 = dt * dz(t0 + dt / 2, y0 + dy1 / 2, z0 + dz1 / 2);
			dy3 = dt * dy(t0 + dt / 2, y0 + dy2 / 2, z0 + dz2 / 2);
			dz3 = dt * dz(t0 + dt / 2, y0 + dy2 / 2, z0 + dz2 / 2);
			dy4 = dt * dy(t0 + dt, y0 + dy3, z0 + dz3);
			dz4 = dt * dz(t0 + dt, y0 + dy3, z0 + dz3);
			t = t0 + dt;
			y = y0 + (dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6);
			z = z0 + (dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6);
			cout << "t: " << t << "; y: " << y << "; z: " << z << endl;
		}
	}
	return 0;
}