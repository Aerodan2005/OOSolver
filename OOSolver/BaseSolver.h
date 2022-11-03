#pragma once
#include "MathClass.h"
#include "General_Utils.h"

class BaseSolver
{
public:
	double* solution = nullptr;
	const char* solver_name = nullptr;

	virtual void Init(MathClass* mc) = 0;
	virtual bool Solve() = 0;

	void RunSolver(MathClass* mc)
	{
		Init(mc);
		Solve();
	}
};

