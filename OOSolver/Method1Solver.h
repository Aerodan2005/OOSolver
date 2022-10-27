#pragma once
#include "BaseSolver.h"
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
		int xxx = mc->probSize;
		std::cout << "In Method1Solver>>Solve: " << xxx << "\n";
		return true;
	}




};

