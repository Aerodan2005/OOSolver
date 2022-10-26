#pragma once
#include "MathClass.h"
#include "General_Utils.h"

class BaseSolver
{
	double* solution = nullptr;
public:
	virtual void Init(MathClass* mc) = 0;
	virtual bool Solve() = 0;
};

