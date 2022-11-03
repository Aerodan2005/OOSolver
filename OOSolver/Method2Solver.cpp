//  Gaussian Elimination solver
#include <iostream>
#include "Method2Solver.h"
using namespace std;



bool Method2Solver::solverProcedure() {
	cout << "\nsolver Procedure start\n";
	int S = mc->probSize; // this is a local var for matrix size
	double*& M = mc->M;  // this is a local var for matrix 
	double*& b = mc->b; //his is a local var for vector
	
	partialPivoting(S,M,b);
	calcResult(S, M, b);


	printMatrix(S,M);
	printVec(S,b);

	return true;
}

void Method2Solver::partialPivoting(int s, double*& M, double*& b) {
	double divisor ;	//the divider number for sum the row	
	for (int row = 1; row < s; row++) {	//the tecnic is fix column by column
		for (int rowCounter = row; rowCounter < s; rowCounter++) {	// and get inside to relevant row
			divisor = M[(rowCounter) * s + (row-1)] / (M[(row - 1) * s + (row - 1)]);
			for (int column = 0; column < s; column++)	{
				M[rowCounter * s + column] -= divisor * M[(row - 1) * s + column];
			}
			b[rowCounter] -= divisor*b[row - 1];
		}
	}
}

void Method2Solver::calcResult(int s, double*& M, double*& b) {

};