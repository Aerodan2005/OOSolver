#include "General_Utils.h"
using namespace std;

bool isSingular(double* mat, int n)
// This function returns TRUE if matrix "mat" is singular, otherwise FALSE 
{
	return CalcDeterminant(mat, n) == 0;
}

void DisplayResult(double* vec, int size)
// This function displays result vector "vec"
{
	cout << "The result is" << endl;
	for (int i = 0; i < size; i++)
		cout << vec[i] << endl;
	cout << endl;
}

double CalcDeterminant(double* mat, int n)
// This function calculates the determinant of a square matrix "mat" of size n*n  
{
	if (n == 1) return mat[0];
	if (n == 2) return ((mat[0] * mat[3]) - (mat[1] * mat[2]));

	double* submatrix = new double[n * n];
	double det = 0;
	int subi = 0, subj = 0;
	for (int x = 0; x < n; x++) 
	{
		subi = 0;
		subj = 0;
		for (int i = 1; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				if (j == x) continue;
				submatrix[subi * (n - 1) + subj] = mat[i * n + j];
				subj++;
			}

			if (subj == n - 1)
			{
				subi++;
				subj = 0;
			}
		}
		det += (pow(-1, x) * mat[x] * CalcDeterminant(submatrix, n - 1));
	}

	delete[] submatrix;
	return det;
}

bool isZeroVector(double* b, int n)
// This function returns TRUE if all values of vector "b" are zeros, otherwise FALSE 
{
	for (int i = 0; i < n; i++)
		if (b[i] != 0) return false;
	return true;
}

bool Multi_MatrixWithVector(int size, double* mat, double* vec, double*& result)
// This function calculates the multiplication of matrix "mat" and vector "vec"
// and stored the output in "result"
{
	result = new double[size];

	for (int i = 0; i < size; i++)
	{
		result[i] = 0;
		for (int j = 0; j < size; j++)
			result[i] += (mat[i * size + j] * vec[j]);
	}
	return 0;
};

void printMatrix(int size, double* mat) 
// This function displays the matrix "mat"
{
	for (int i = 0; i < size; i++)
	{
		cout << "|";
		for (int j = 0; j < size; j++)
			cout << mat[i * size + j] << " ";
		cout << "|\n";
	}
}