#pragma once
class BaseSolver
{
  int order = 0;
  double * matrix = nullptr;
  double * outputVec = nullptr;
  double * solution = nullptr;

public:
  virtual void InitProblem (int size, double * matData, double * bVecData) = 0;
  virtual bool Solve () = 0;
};

