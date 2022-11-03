#pragma once
#include "BaseSolver.h"
#include "General_Utils.h"
#include <iostream>

class Method1Solver : public BaseSolver
{
	MathClass* mc = 0;

public:
	void Init(MathClass* mc) override 
	{
		this->mc = mc;
		solver_name = "QR Solver";
		cout << endl << solver_name << endl;
	}

	bool Solve() override
	{
		double* vec = nullptr;
		double* Q = nullptr;
		double* R = nullptr;
		QRdecomp(mc->probSize, mc->M, Q, R);
		Multi_MatrixWithVector(mc->probSize, Q, mc->b, vec);
		BackSub(mc->probSize, R, vec, solution);
		DisplayResult(solution, mc->probSize);

		if (Q != nullptr) delete[] Q;
		if (R != nullptr) delete[] R;
		if (vec != nullptr) delete[] vec;
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
	void FlipColumnSigns(double*& mat, int size, int col);
	void Calculate_Q(int size, double* A, double*& Q, double*& e_mat);
	void Calculate_R(int size, double* A, double*& R, double*& e_mat);

};

