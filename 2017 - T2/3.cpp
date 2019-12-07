#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> results = { 0,0,0 };
	double result, h = 1, err, dx = 0.25;
	int counter;
	vector<double> list = { 1.04,0.37,0.38,1.49,1.08,0.13,0.64,0.84,0.12 };
	for (int j = 0; j < 3; j++)
	{
		result = list[0];
		counter = 1;
		for (int i = h/dx; i < list.size() - h/dx; i += h/dx)
		{
			if (counter % 2 == 0)
				result += list[i] * 2;
			else
				result += list[i] * 4;
			counter++;
		}
		result += list[list.size() - 1];
		result *= h / 3;
		cout << "Step: " << h << "; Result: " << result << endl;
		results[j] = result;
		h /= 2;
	}
	err = (results[2] - results[1])/15;
	cout << "Error: " << err;
	return 0;
}