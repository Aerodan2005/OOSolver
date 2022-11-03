#include "Method1Solver.h"

bool Method1Solver::BackSub(int size, double* mat, double* vec, double*& result)
// This function solves mat*x = vec
// where mat is an upper triangular matrix
{
	result = new double[size] {0};
	double sum = 0;
	for (int i = 0; i < size; i++)
		result[i] = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j < size; j++)
			sum = sum + result[j] * mat[i + size * j];

		result[i] = (1 / mat[size * i + i]) * (vec[i] - sum);
	}
	return 0;
}

double Method1Solver::DotCalc(double* vec1, double* vec2, int size)
// This function returns to dot product of vectors "vec1" and "vec2"
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += vec1[i] * vec2[i];

	return sum;
}

void Method1Solver::VecNorm(double* vec, int size, double*& result)
// This function stores the normalized vector "vec" in "result"
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += (vec[i]) * (vec[i]);

	sum = pow(sum, 0.5);

	for (int i = 0; i < size; i++)
		result[i] = vec[i] / sum;
}

bool Method1Solver::TransposeMat(double* mat, int size, double*& result)
// This function transpose matrix "mat" and stores it in matrix "result"
{
	//result = new double[size * size] {0};
	if (size == 1)
	{
		result = mat;
		return 0;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			result[i + size * j] = GetCellij(mat, size, i, j);

	return 0;
}

double Method1Solver::GetCellij(double* mat, int size, int row, int col)
// This function returns the value of mat[i,j]
{
	return (mat[col + size * row]);
}

void Method1Solver::GetRow(double* mat, int size, int i, double*& vec)
// This function stores row "i" of matrix "mat" in "vec"
{
	//vec = new double[size] {0};
	for (int j = 0; j < size; j++)
		vec[j] = GetCellij(mat, size, i, j);
}

void Method1Solver::GetColumn(double* mat, int size, int i, double*& vec)
// This function stores column "i" of matrix "mat" in "vec"
{
	//vec = new double[size] {0};
	for (int j = 0; j < size; j++)
		vec[j] = GetCellij(mat, size, j, i);
}

void Method1Solver::FlipColumnSigns(double*& mat, int size, int col)
// This function flips the signs of column "col" of matrix "mat"
{
	for (int i = 0; i < size; i++)
		mat[i + size * col] = -mat[i + size * col];
}

bool Method1Solver::QRdecomp(int size, double* A, double*& Q, double*& R)
{
	// This function performs Gram-Schmidt process
	// to achieve QR decomposition so that 
	// mat = Q*R
	// where R is an upper trianglular matrix and Q is an orthogonal matrix

	Q = new double[size * size] {0};
	R = new double[size * size] {0};
	double* e_mat = new double[size * size] {0};

	Calculate_Q(size, A, Q, e_mat);
	Calculate_R(size, A, R, e_mat);

	delete[] e_mat;
	return 0;
}

void Method1Solver::Calculate_Q(int size, double* A, double*& Q, double*& e_mat)
{
	double* a_vec = new double[size] {0};
	double* e_vec = new double[size] {0};
	double* u_vec = new double[size] {0};
	double dot_prod = 0;

	for (int col = 0; col < size; col++)
	{
		GetColumn(A, size, col, a_vec);
		GetColumn(A, size, col, u_vec);

		for (int i = 0; i < col; i++)
		{
			GetColumn(e_mat, size, i, e_vec);
			dot_prod = DotCalc(a_vec, e_vec, size);
			for (int k = 0; k < size; k++)
				u_vec[k] -= dot_prod * e_vec[k];
		}

		// Save values to temp matrix e
		VecNorm(u_vec, size, e_vec);
		for (int k = 0; k < size; k++)
			e_mat[col + size * k] = e_vec[k];
	}
	// Save transposed e matrix to Q
	TransposeMat(e_mat, size, Q);

	// Flip first column signs
	FlipColumnSigns(Q, size, 0);
	delete[] a_vec;
	delete[] e_vec;
	delete[] u_vec;
}

void Method1Solver::Calculate_R(int size, double* A, double*& R, double*& e_mat)
{
	double* a_vec = new double[size] {0};
	double* e_vec = new double[size] {0};

	for (int col = 0; col < size; col++)
	{
		GetColumn(A, size, col, a_vec);
		for (int row = 0; row <= col; row++)
		{
			GetColumn(e_mat, size, row, e_vec);
			R[col + size * row] = DotCalc(a_vec, e_vec, size);
		}
	}
	FlipColumnSigns(R, size, 0);
	TransposeMat(R, size, R);
	delete[] a_vec;
	delete[] e_vec;
}