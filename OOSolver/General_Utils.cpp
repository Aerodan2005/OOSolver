#include "General_Utils.h"
using namespace std;

bool isSingular(double* matrix, int n)
{
	return CalcDeterminant(matrix, n) == 0;
}

void DisplayResult(double* vec, int size)
{
	cout << "The result is" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << endl;
	}
	cout << endl;
}

double CalcDeterminant(double* matrix, int n)
// This function calculates the determinant of a square matrix of size n*n  
{
	if (n == 1)
		return matrix[0];

	if (n == 2)
		return ((matrix[0] * matrix[3]) - (matrix[1] * matrix[2]));

	double det = 0;
	double* submatrix = new double[n * n];
	for (int x = 0; x < n; x++) {
		int subi = 0;
		int subj = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == x)
					continue;
				submatrix[subi * (n - 1) + subj] = matrix[i * n + j];
				subj++;
			}
			if (subj == n - 1)
			{
				subi++;
				subj = 0;
			}
		}
		det += (pow(-1, x) * matrix[x] * CalcDeterminant(submatrix, n - 1));
	}

	delete[] submatrix;
	return det;
}

bool isZeroVector(double* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i] != 0) return false;
	}
	return true;
}

bool Multi_MatrixWithVector(int size, double* mat, double* vec, double*& result)
{
	result = new double[size];

	for (int i = 0; i < size; i++)
	{
		result[i] = 0;
		for (int j = 0; j < size; j++)
		{
			result[i] += (mat[i * size + j] * vec[j]);
		}
	}
	return 0;
};

void printMatrix(int size, double* mat) {
	for (int i = 0; i < size; i++)
	{
		cout << "|";
		for (int j = 0; j < size; j++)
		{
			cout << mat[i * size + j] << " ";
		}
		cout << "|\n";
	}
}