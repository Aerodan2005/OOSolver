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

	bool Solve() override
	{
		int xxx = mc->probSize;
		std::cout << "In Method2Solver>>Solve: " << xxx << "\n";
		return true;
	}
};
