#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> f = { 0.18,0.91,0.83,1.23,0.88,1.37,0.80,1.34,0.43 }, sums = { 0,0,0 };
	double h = 0.8, x = 0, sum = 0, err;
	int counter;
	for (int i = 0; i < 3; i++)
	{
		x = 0;
		counter = 1;
		sum = f[x / 0.2];
		x = counter*h;
		while (x < 1.5)
		{
			if (counter % 2 == 0)
				sum += 2 * f[x / 0.2];
			else
				sum += 4 * f[x / 0.2];
			counter++;
			x = counter*h;
		}
		sum += f[x / 0.2];
		cout << (h/3)*sum << endl;
		sums[i] = (h/3)*sum;
		h /= 2;
	}
	err = (sums[2] - sums[1]) / 15;
	cout << "Error: " << err;
	return 0;
}