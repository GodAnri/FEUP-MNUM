#include <iostream>
#include <vector>

using namespace std;

double f(double x)
{
	return sqrt(1 + pow(2.5*exp(2.5*x),2));
}

int main()
{
	vector<double> sumss = { 0,0,0 };
	vector<double> sumst = { 0,0,0 };
	double a = 0, b = 1, h = 0.125, sums, sumt;
	int n;
	for (int i = 0; i < 3; i++)
	{
		n = (b - a) / h;
		sums = f(a) + f(b);
		sumt = f(a) + f(b);
		for (int k = 1; k < n; k++)
		{
			sumt += 2 * f(k*h);
			if (k % 2 == 0)
				sums += 2 * f(k*h);
			else
				sums += 4 * f(k*h);
		}
		sumss[i] = (h / 3)*sums;
		sumst[i] = (h / 2)*sumt;
		h /= 2;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Simpson: " << sumss[i] << "; Trapezios: " << sumst[i] << endl;
	}
	double qcs = (sumss[1] - sumss[0]) / (sumss[2] - sumss[1]), qct = (sumst[1] - sumst[0]) / (sumst[2] - sumst[1]), ers = (sumss[2] - sumss[1]) / (16 - 1), ert = (sumst[2] - sumst[1]) / (4 - 1);
	cout << "QCS: " << qcs << "; QCT: " << qct << "; ErS: " << ers << "; ErT: " << ert;
	return 0;
}