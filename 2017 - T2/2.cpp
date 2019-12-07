#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> result = { 2.12687,2.39858,3.99517,-3.73040 };
	vector<vector<double>> matrix = { {6,0.5,3,0.25}, {1.2,3,0.25,0.2}, {-1,0.25,4,2}, {2,4,1,8} };
	vector<double> sol_list = { 25,10,7,-12 };
	for (int i = 0; i < matrix.size(); i++)
	{
		result[i] = sol_list[i];
		for (int j = 0; j < matrix.size(); j++)
		{
			if (j != i)
				result[i] -= result[j]*matrix[i][j];
		}
		result[i] /= matrix[i][i];
	}
	cout << "Results: ";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "; ";
	return 0;
}