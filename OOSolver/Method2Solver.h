#pragma once
#include "BaseSolver.h"
#include <iostream>

class Method2Solver : public BaseSolver
{
	MathClass* mc;
public:
	void Init(MathClass* mc) override {
		this->mc = mc;
	}
	bool Solve()override {
		//int a = mc->probSize;
		std::cout << "In Method_2_Solver>>Solve: " << mc->probSize << "\n";
		solverProcedure();
		return true;
	}
private:
	bool solverProcedure();
	void partialPivoting(int S, double*& M, double*& b);
	void calcResult(int s, double*& M, double*& b);
};
