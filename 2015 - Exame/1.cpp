#include <iostream>

using namespace std;

double dT(double T)
{
	return -0.25*(T - 37);
}

int main()
{
	double T = 3, t = 5, dt = 0.4;
	for (int i = 0; i < 2; i++)
	{
		t += dt;
		T += dt * dT(T);
	}
	cout << T;
	return 0;
}