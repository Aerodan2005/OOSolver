#pragma once
#include "BaseSolver.h"
#include "General_Utils.h"
#include <iostream>

class Method1Solver : public BaseSolver
{
	MathClass* mc;
public:
	void Init(MathClass* mc) override {
		this->mc = mc;
	}

	bool Solve() override
	{
		double* result = nullptr;
		double* result2 = nullptr;
		double* Q;
		double* R;
		QRdecomp(mc->probSize, mc->M, Q, R);
		Multi_MatrixWithVector(mc->probSize, Q, mc->b, result);
		BackSub(mc->probSize, R, result, result2);
		DisplayResult(result2, mc->probSize);
		return true;
	}

private:
	bool BackSub(int size, double* mat, double* vec, double*& result);
	bool QRdecomp(int size, double* mat, double*& Q, double*& R);
	double DotCalc(double* vec1, double* vec2, int size);
	bool TransposeMat(double* mat, int size, double*& result);
	double GetCellij(double* mat, int size, int i, int j);
	void GetRow(double* mat, int size, int i, double*& vec);
	void GetColumn(double* mat, int size, int i, double*& vec);
	void VecNorm(double* vec, int size, double*& result);
};

