#pragma once
#include "BaseSolver.h"
#include "General_Utils.h"
#include <iostream>

class Method3Solver : public BaseSolver
{
	MathClass* mc = 0;

public:	
	void Init(MathClass* mc) override
	{
		this->mc = mc;
		solver_name = "Cramer Solver";
		cout << endl << solver_name << endl;
	}

	bool Solve() override
	{
		double* solution = new double [mc->probSize] {0};
		double* mat = new double [mc->probSize * mc->probSize] {0};
		double det = CalcDeterminant(mc->M, mc->probSize);

		for (int i = 0; i < mc->probSize; i++)
		{
			CopyMatrix(mc->M, mc->probSize, mat);
			ReplaceColumn(mat, mc->b, i, mc->probSize, mat);
			solution[i] = CalcDeterminant(mat, mc->probSize) / det;
		}

		DisplayResult(solution, mc->probSize);
		if (solution != nullptr) delete[] solution;
		if (mat != nullptr) delete[] mat;

		return true;
	}

private:
	void ReplaceColumn(double* mat, double* vec, int col, int size, double*& result);
	void CopyMatrix(double* mat1, int size, double*& result);
};

