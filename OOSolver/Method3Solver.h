#pragma once
#include "BaseSolver.h"
#include "General_Utils.h"
#include <iostream>

class Method3Solver : public BaseSolver
{
	MathClass* mc;
public:
	void Init(MathClass* mc) override {
		this->mc = mc;
	}

	//bool BackSub(int size, double* mat, double* vec, double*& result);
	//bool QRdecomp(int size, double* mat, double*& Q, double*& R);
	//double DotCalc(double* vec1, double* vec2, int size);
	//bool TransposeMat(double* mat, int size, double*& result);
	//double GetCellij(double* mat, int size, int i, int j);
	//void GetRow(double* mat, int size, int i, double*& vec);
	//void GetColumn(double* mat, int size, int i, double*& vec);
	//void VecNorm(double* vec, int size, double*& result);

	void ReplaceColumn(double* mat, double* vec, int col, int size, double*& result);
	void CopyMatrix(double* mat1, int size, double*& result);

	bool Solve() override
	{
		double* result = new double [mc->probSize] {0};
		double det = 0;
		double* mat1 = new double [mc->probSize * mc->probSize] {0};
		double* mat2 = new double [mc->probSize * mc->probSize] {0};

		det = CalcDeterminant(mc->M, mc->probSize);
		for (int i = 0; i < mc->probSize; i++)
		{
			CopyMatrix(mc->M, mc->probSize, mat1);
			ReplaceColumn(mat1, mc->b, i, mc->probSize, mat2);
			result[i] = CalcDeterminant(mat2, mc->probSize) / det;
		}

		DisplayResult(result, mc->probSize);
		return true;
	}
};

