#include "Method3Solver.h"

void Method3Solver::ReplaceColumn(double* mat, double* vec, int col, int size, double*& result)
{

}

void Method3Solver::CopyMatrix(double* mat1, int size, double*& result)
{
	for (int i = 0; i < size * size; i++)
		result[i] = mat1[i];
}




//bool Method3Solver::BackSub(int size, double* mat, double* vec, double*& result)
// This function solves mat*x = vec
// where mat is an upper triangular matrix
//{
//	result = new double[size];
//	double sum;
//	for (int i = 0; i < size; i++)
//		result[i] = 0;
//
//	for (int i = size - 1; i >= 0; i--)
//	{
//		sum = 0;
//		for (int j = i + 1; j < size; j++)
//		{
//			sum = sum + result[j] * mat[i + size * j];
//		}
//		result[i] = (1 / mat[size * i + i]) * (vec[i] - sum);
//	}
//	return 0;
//}

//double Method3Solver::DotCalc(double* vec1, double* vec2, int size)
//{
//	double sum = 0;
//	for (int i = 0; i < size; i++)
//		sum += vec1[i] * vec2[i];
//	return sum;
//}

//void Method3Solver::VecNorm(double* vec, int size, double*& result)
//{
//	double sum = 0;
//	for (int i = 0; i < size; i++)
//		sum += (vec[i]) * (vec[i]);
//	sum = pow(sum, 0.5);
//	for (int i = 0; i < size; i++)
//		result[i] = vec[i] / sum;
//}

//bool Method3Solver::TransposeMat(double* mat, int size, double*& result)
//{
//	result = new double[size * size] {0};
//	if (size == 1)
//	{
//		result = mat;
//		return 0;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (i == j)
//				result[i + size * i] = GetCellij(mat, size, i, i);
//			else
//				result[i + size * j] = GetCellij(mat, size, i, j);
//		}
//	}
//	return 0;
//}

//double Method3Solver::GetCellij(double* mat, int size, int row, int col)
//{
//	return (mat[col + size * row]);
//}

//void Method3Solver::GetRow(double* mat, int size, int i, double*& vec)
//{
//	vec = new double[size] {0};
//	for (int j = 0; j < size; j++)
//		vec[j] = GetCellij(mat, size, i, j);
//}

//void Method3Solver::GetColumn(double* mat, int size, int i, double*& vec)
//{
//	vec = new double[size] {0};
//	for (int j = 0; j < size; j++)
//		vec[j] = GetCellij(mat, size, j, i);
//}

//bool Method3Solver::QRdecomp(int size, double* A, double*& Q, double*& R)
//{
//	// This function performs Gram-Schmidt process
//	// to achieve QR decomposition so that 
//	// mat = Q*R
//	// where R is an upper trianglular matrix and Q is an orthogonal matrix
//
//	Q = new double[size * size] {0};
//	R = new double[size * size] {0};
//
//	double* det = new double[size * size] {0};
//	double* u = new double[size * size] {0};
//	double* sumvec = new double[size] {0};
//	double* a_vec = new double[size] {0};
//	double* e_vec = new double[size] {0};
//	double* u_vec = new double[size] {0};
//	double det = 0;
//
//	// Calculate matrix Q
//	for (int col = 0; col < size; col++)
//	{
//		GetColumn(A, size, col, a_vec);
//		GetColumn(A, size, col, u_vec);
//
//		for (int i = 0; i < col; i++)
//		{
//			GetColumn(e, size, i, e_vec);
//			dot_prod = DotCalc(a_vec, e_vec, size);
//			for (int k = 0; k < size; k++)
//			{
//				u_vec[k] -= dot_prod * e_vec[k];
//			}
//		}
//
//		// Save values to temp matrix e
//		VecNorm(u_vec, size, e_vec);
//		for (int k = 0; k < size; k++)
//		{
//			e[col + size * k] = e_vec[k];
//		}
//	}
//	// Save transposed e matrix to  Q
//	TransposeMat(e, size, Q);
//
//	for (int i = 0; i < size; i++)
//	{
//		Q[i] = -Q[i];
//	}
//
//	// Calculating matrix R
//	for (int col = 0; col < size; col++)
//	{
//		for (int row = 0; row <= col; row++)
//		{
//			GetColumn(A, size, col, a_vec);
//			GetColumn(e, size, row, e_vec);
//			R[col + size * row] = DotCalc(a_vec, e_vec, size);
//		}
//	}
//
//	TransposeMat(R, size, R);
//	for (int i = 0; i < size; i++)
//	{
//		R[size * i] = -R[size * i];
//	}
//
//	delete[] e, u, sumvec, a_vec, e_vec, u_vec;
//	return 0;
//}

