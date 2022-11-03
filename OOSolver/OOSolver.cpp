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
#include "Method3Solver.h"
#include "MathClass.h"
#include <cmath>
using namespace std;
int main(int argc, char** argv)
{
	MathClass p0;
	bool res1 = p0.LoadInput();
	p0.PrintData();

	if (!p0.isInputValid())
		return 0;

	bool solver1_flag = true;
	bool solver2_flag = true;
	bool solver3_flag = true;

	// solver 1
	if (solver1_flag) {
		BaseSolver* bs1 = new Method1Solver();
		bs1->RunSolver(&p0);
		delete bs1;
	};

	//solver 2
	if (solver2_flag) {
		BaseSolver* bs2 = new Method2Solver();
		bs2->RunSolver(&p0);
		delete bs2;
	};

	// solver 3
	if (solver3_flag) {
		BaseSolver* bs3 = new Method3Solver();
		bs3->RunSolver(&p0);
		delete bs3;
	};
}
