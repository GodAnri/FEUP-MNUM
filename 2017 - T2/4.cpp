#include <iostream>
#include <vector>

using namespace std;

int main()
{
	double sum = 0;
	vector<vector<double>> xy = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2} };
	{
		for (int i = 0; i < xy.size(); i++)
		{
			for (int j = 0; j < xy.size(); j++)
			{
				if ((i == 0 || i == xy.size() - 1) && (j == 0 || j == xy.size() - 1))
				{
					sum += xy[i][j];
				}
				else if (i == 0 || j == 0 || i == xy.size() - 1 || j == xy.size() - 1)
				{
					sum += 2 * xy[i][j];
				}
				else
				{
					sum += 4 * xy[i][j];
				}
			}
		}
	}
	sum /= 4;
	cout << "Sum: " << sum;
	return 0;
}