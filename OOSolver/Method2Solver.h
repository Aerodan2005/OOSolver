#pragma once
#include "BaseSolver.h"
#include "General_Utils.h"
#include <iostream>
using namespace std;

class Method2Solver : public BaseSolver
{
	MathClass* mc;
public:
	void Init(MathClass* mc) override
	{
		this->mc = mc;
		solver_name = "Gaussian Elimination - Partial Pivoting";
		cout << endl << solver_name << endl;
	}

	bool Solve()override {
		return (solverProcedure());
	}
private:
	bool solverProcedure();
	void partialPivoting(int S, double*& M, double*& b);
	void calcPivot(int s, double*& M, double*& b, double*& result);
};
