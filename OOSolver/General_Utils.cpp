#include "General_Utils.h"

bool isSingular(double* matrix, int n)
{
	return CalcDeterminant(matrix, n) == 0;
}

double CalcDeterminant(double* matrix, int n)
// This function calculates the determinant of a square matrix using recursion  
{
	double det = 0;
	double submatrix[10]; // 10 is the limit of the dimension size
	if (n == 2)
		return ((matrix[0] * matrix[3]) - (matrix[1] * matrix[2]));
	else {
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
			det = det + (pow(-1, x) * matrix[x] * CalcDeterminant(submatrix, n - 1));
		}
	}
	return det;
}

bool isZeroVector(double* b, int n)
{
	for (int i = 0; i < n; i++)
		if (b[i] != 0) return false;
	return true;
}

bool MultiMatrixWithVector(int size, double* mat, double* vec)
{
	double* vecSol = new double[size];

	for (int i = 0; i < size; i++) 
	{
		vecSol[i] = 0;
		for (int j = 0; j < size; j++) 
		{
			//cout << mat[i*size+j] << "_";
			vecSol[i]= vecSol[i]+(mat[i * size + j] * vec[j]);
		}
		cout << vecSol[i];
		cout << "\n";
	}


	for (int i = 0; i < size; i++)
	{
		cout << "|";
		for (int j = 0; j < size; j++)
		{
			cout << mat[i * size + j] << " ";
		}
		cout << "| ";
			if (i == 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			cout << " |" << vec[i] << "|";
			if (i == 1)
			{
				cout << "=";
			}
			else 
			{
				cout << " ";
			}
			cout << " |" << vecSol[i] << "|" << "\n";
	}




	delete vecSol;

	return 0;
};