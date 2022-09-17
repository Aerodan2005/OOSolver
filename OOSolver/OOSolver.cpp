// OOSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseSolver.h"
#include "Method1Solver.h"

int main(int argc, char** argv)
{
  std::cout << "OO Solver, received: " << argc << " arguments\n";
  BaseSolver * bs = new Method1Solver ();
  bs->InitProblem(5, nullptr, nullptr);
  bs->Solve();
}
