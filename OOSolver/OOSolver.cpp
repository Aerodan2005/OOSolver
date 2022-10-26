// OOSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// INPUT: (in file Input.txt)
// 1) n - dimension size of the problem 
// 2) M - matrix of size n*n
// 3) b - vector of size n
// 
// OUTPUT: 
// 1) x - vector of size n
//This program solves the equation Mx=b subject to x. 
//The solution is calculated using various solvers.
//The program checks the validity of M,b for cases of infinite solutions and no solutions.
//For valid input, the solution is provided as the answer vector of size n for each solver.

#include <iostream>
#include "General_Utils.h"
#include "BaseSolver.h"
#include "Method1Solver.h"
#include "Method2Solver.h"
#include "MathClass.h"
#include <cmath>
using namespace std;
int main(int argc, char** argv)
{
	MathClass p1;
	bool res = p1.LoadInput();
	p1.PrintData();
	MultiMatrixWithVector(p1.probSize, p1.M, p1.b);

	//BaseSolver alolo;
 	cout << endl << "OO Solver, received: " << argc << " arguments\n";
	// Solve method1
	BaseSolver * bs = new Method1Solver ();
	bs->InitProblem(p1.probSize, p1.M, p1.b);
	bs->Solve();
	delete bs;

	// Solve method2
	bs = new Method2Solver();
	bs->InitProblem(p1.probSize, p1.M, p1.b);
	bs->Solve();
	delete bs;

	//int x; cin >> x;
}
