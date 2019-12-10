#include <iostream>
#include <vector>

using namespace std;

double dC(double T, double C)
{
	return -exp(-0.5 / (T + 273))*C;
}

double dT(double T, double C)
{
	return 20*exp(-0.5 / (T + 273))*C - 0.5*(T - 20);
}

int main()
{
	vector<double> sol_list = { 0,0,0 };
	cout << "a) EULER:" << endl;
	double t = 0, C = 1, T = 15, deltaC, deltaT, h = 0.25;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "C: " << C << endl;
		cout << "T: " << T << endl;
		deltaC = h * dC(T, C);
		deltaT = h * dT(T, C);
		C += deltaC;
		T += deltaT;
		t += h;
	}
	sol_list[0] = C;
	cout << endl;
	cout << "b) RUNGE KUTTA:" << endl;
	t = 0;
	C = 1;
	T = 15;
	double dC1, dC2, dC3, dC4, dT1, dT2, dT3, dT4;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "C: " << C << endl;
		cout << "T: " << T << endl;
		dC1 = h * dC(T, C);
		dT1 = h * dT(T, C);
		dC2 = h * dC(T + dT1 / 2, C + dC1 / 2);
		dT2 = h * dT(T + dT1 / 2, C + dC1 / 2);
		dC3 = h * dC(T + dT2 / 2, C + dC2 / 2);
		dT3 = h * dT(T + dT2 / 2, C + dC2 / 2);
		dC4 = h * dC(T + dT3, C + dC3);
		dT4 = h * dT(T + dT3, C + dC3);
		C += dC1/6 + dC2/3 + dC3/3 + dC4/6;
		T += dT1/6 + dT2/3 + dT3/3 + dT4/6;
		t += h;
	}
	cout << "c) QC and Error on Euler:" << endl;
	double qc, err;
	h /= 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			deltaC = h * dC(T, C);
			deltaT = h * dT(T, C);
			C += deltaC;
			T += deltaT;
			t += h;
		}
		sol_list[i + 1] = C;
		h /= 2;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << " : " << sol_list[i] << endl;
	}
	qc = (sol_list[1] - sol_list[0]) / (sol_list[2] - sol_list[1]);
	err = abs(sol_list[2] - sol_list[1]);
	cout << "QC: " << qc << endl;
	cout << "Epsilon: " << err << endl;
	return 0;
}