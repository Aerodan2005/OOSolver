#pragma once
#include <iostream>
#include "BaseSolver.h"
class Method2Solver :
    public BaseSolver
{
public:
    void InitProblem(int size, double* matData, double* bVecData) override {}
    bool Solve() override {
        std::cout << "In Method1Solver>>Solve\n";
        return true;
    }
};

