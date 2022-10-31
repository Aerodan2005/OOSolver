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
	//p1 data for solver 1
	MathClass p1;
	bool res1 = p1.LoadInput();
	p1.PrintData();	
	//cout << endl << "Solver, received: " << argc << " arguments\n";
	
	// Solve method1
	BaseSolver * bs1 = new Method1Solver ();
	bs1->Init(&p1);
	bs1->Solve();
	delete bs1;

	// p2 data for solver 2
	MathClass p2;
	bool res2 = p2.LoadInput();
	p2.PrintData();
	//cout << endl << "Solver, received: " << argc << " arguments\n";

	// Solve method2
	BaseSolver* bs2 = new Method2Solver();
	bs2->Init(&p2);
	bs2->Solve();
	delete bs2;
}
