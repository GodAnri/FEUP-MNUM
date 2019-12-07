#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<double>> matrix = { {18,-1,1},{3,-5,4},{6,8,29} };
	double coefficient_error = 0.1;
	vector<double> sol_list = { 0.552949, -0.15347, -0.10655 };
	vector<double> err_list = { 0, 0, 0 };
	double div = 0, mul = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		err_list[i] = coefficient_error * (1 - sol_list[0] - sol_list[1] - sol_list[2]);
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		div = matrix[i][i];
		for (int j = i; j < matrix.size(); j++)
		{
			matrix[i][j] /= div;
		}
		err_list[i] /= div;
		for (int j = i + 1; j < matrix.size(); j++)
		{
			mul = matrix[j][i];
			for (int k = i; k < matrix.size(); k++)
			{
				matrix[j][k] -= matrix[i][k] * mul;
			}
			err_list[j] -= err_list[i] * mul;
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "|" << err_list[i] << endl;
	}
	for (int i = matrix.size() + 1; i >= 0; i--)
	{
		for (int j = i + 1; j < matrix.size(); j++)
		{
			err_list[i] -= matrix[i][j] * err_list[j];
		}
	}
	cout << "Delta x: " << err_list[0] << endl;
	cout << "Delta y: " << err_list[1] << endl;
	cout << "Delta z: " << err_list[2] << endl;
	return 0;
}