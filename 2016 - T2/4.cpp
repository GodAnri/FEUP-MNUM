#include <iostream>

using namespace std;

double dT(double T)
{
	return -0.25*(T - 42);
}

int main()
{
	double T = 10, t = 5, h = 0.4;
	for (int i = 0; i < 2; i++)
	{
		T += h*dT(T);
	}
	cout << T;
	return 0;
}