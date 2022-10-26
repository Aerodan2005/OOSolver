#pragma once
#include "BaseSolver.h"
#include <iostream>

class Method1Solver :  public BaseSolver
{
public:
  void InitProblem(int size, double* matData, double* bVecData) override {}
  
  bool Solve() override 
  {
    std::cout << "In Method1Solver>>Solve\n";
    return true;
  }
};

