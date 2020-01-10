#include <iostream>
#include <vector>

using namespace std;

double dC(double C, double T, double t)
{
	return -exp(-0.5 / (T + 273))*C;
}

double dT(double C, double T, double t)
{
	return 30*exp(-0.5 / (T + 273))*C - 0.5*(T-20);
}

int main()
{
	vector<double> euler = { 0,0,0 };
	double t = 0, dt = 0.25, C = 2.5, T = 25, deltaC, deltaT;
	for (int k = 0; k < 3; k++)
	{
		t = 0;
		C = 2.5;
		T = 25;
		for (int i = 0; i < 0.5/dt; i++)
		{
			t += dt;
			deltaC = dC(C, T, t);
			deltaT = dT(C, T, t);
			C += deltaC * dt;
			T += deltaT * dt;
			if (k == 0)
				cout << "t: " << t << "; C: " << C << "; T: " << T << endl;
		}
		euler[k] = T;
		cout << "Step: " << dt << "; C: " << T << endl;
		dt /= 2;
	}
	t = 0;
	dt = 0.25;
	C = 2.5;
	T = 25;
	double dC1, dC2, dC3, dC4, dT1, dT2, dT3, dT4;
	for (int i = 0; i < 2; i++)
	{
		t += dt;
		dC1 = dt * dC(C, T, t);
		dT1 = dt * dT(C, T, t);
		dC2 = dt * dC(C + dC1 / 2, T + dT1 / 2, t + dt / 2);
		dT2 = dt * dT(C + dC1 / 2, T + dT1 / 2, t + dt / 2);
		dC3 = dt * dC(C + dC2 / 2, T + dT2 / 2, t + dt / 2);
		dT3 = dt * dT(C + dC2 / 2, T + dT2 / 2, t + dt / 2);
		dC4 = dt * dC(C + dC3, T + dT3, t + dt);
		dT4 = dt * dT(C + dC3, T + dT3, t + dt);
		C += (dC1 / 6 + dC2 / 3 + dC3 / 3 + dC4 / 6);
		T += (dT1 / 6 + dT2 / 3 + dT3 / 3 + dT4 / 6);
		cout << "t: " << t << "; C: " << C << "; T: " << T << endl;
	}
	cout << "QC: " << (euler[1] - euler[0]) / (euler[2] - euler[1]) << "; Err: " << (euler[2] - euler[1]);
	return 0;
}