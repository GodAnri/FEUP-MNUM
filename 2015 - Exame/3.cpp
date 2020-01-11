#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<double>> matrix = { {1,0.5,1 / 3.0},{0.5,1 / 3.0,0.25},{1 / 3.0,0.25,0.2} }, err_matrix = matrix;
	vector<double> b = { -1,1,1 }, sol = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		double div = matrix[i][i];
		for (int j = i; j < 3; j++)
		{
			matrix[i][j] /= div;
		}
		b[i] /= div;
		for (int j = i + 1; j < 3; j++)
		{
			double mul = matrix[j][i];
			for (int k = 0; k < 3; k++)
			{
				matrix[j][k] -= matrix[i][k] * mul;
			}
			b[j] -= b[i] * mul;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "[";
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "\t|";
		}
		cout << b[i] << "]" << endl;
	}
	double result;
	for (int i = 2; i > -1; i--)
	{
		result = b[i];
		for (int j = i + 1; j < 3; j++)
		{
			result -= sol[j] * matrix[i][j];
		}
		sol[i] = result;
	}
	cout << "x1 = " << sol[0] << endl << "x2 = " << sol[1] << endl << "x3 = " << sol[2] << endl;
	
	vector<double> err = { 0.05 - 0.05*sol[0] - 0.05*sol[1] - 0.05*sol[2] , 0.05 - 0.05*sol[0] - 0.05*sol[1] - 0.05*sol[2] , 0.05 - 0.05*sol[0] - 0.05*sol[1] - 0.05*sol[2] };
	for (int i = 0; i < 3; i++)
	{
		double div = err_matrix[i][i];
		for (int j = i; j < 3; j++)
		{
			err_matrix[i][j] /= div;
		}
		err[i] /= div;
		for (int j = i + 1; j < 3; j++)
		{
			double mul = err_matrix[j][i];
			for (int k = 0; k < 3; k++)
			{
				err_matrix[j][k] -= err_matrix[i][k] * mul;
			}
			err[j] -= err[i] * mul;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "[";
		for (int j = 0; j < 3; j++)
		{
			cout << err_matrix[i][j] << "\t|";
		}
		cout << err[i] << "]" << endl;
	}
	for (int i = 2; i > -1; i--)
	{
		result = err[i];
		for (int j = i + 1; j < 3; j++)
		{
			result -= sol[j] * err_matrix[i][j];
		}
		sol[i] = result;
	}
	cout << "deltax1 = " << sol[0] << endl << "deltax2 = " << sol[1] << endl << "deltax3 = " << sol[2] << endl;
	cout << "A incognita mais sensivel a erros nos dados e x3, uma vez que a variacao na solucao e a maior (" << sol[2] << ").";
	return 0;
}