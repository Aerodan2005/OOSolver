#include "Method3Solver.h"

void Method3Solver::ReplaceColumn(double* mat, double* vec, int col, int size, double*& result)
// This function replaces column "col" of matrix "mat" with vector "vec"
// and stores the new matrix in "result"
{
	for (int i = 0; i < size * size; i++)
		result[i] = mat[i];
	for (int i = 0; i < size; i++)
		result[col + size * i] = vec[i];
}

void Method3Solver::CopyMatrix(double* mat1, int size, double*& result)
// This function copies matrix "mat1" into matrix "result"
{
	for (int i = 0; i < size * size; i++)
		result[i] = mat1[i];
}
