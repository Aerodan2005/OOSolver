// OOSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "General_Utils.h"
#include "BaseSolver.h"
#include "Method1Solver.h"
#include "Method2Solver.h"
#include "MathClass.h"
using namespace std;
int main(int argc, char** argv)
{
	MathClass p1;
	p1.PrintMatrix();
	CalcDeterminant(p1.M, p1.a);
	if (isSingular(p1.M, p1.a))
	{
		cout << "Matrix is singular.";
	}


	cout << "OO Solver, received: " << argc << " arguments\n";
	// read the data
	// solve method1
	BaseSolver * bs = new Method1Solver ();
	bs->InitProblem(5, nullptr, nullptr);
	bs->Solve();
	delete bs;
	// solve method2
	bs = new Method2Solver();
	bs->InitProblem(5, nullptr, nullptr);
	bs->Solve();
	delete bs;
}
