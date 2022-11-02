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
	printMatrix(S,M);

	return true;
}

void Method2Solver::partialPivoting(int s, double*& M, double*& B) {
	double divisor ;	//the divider number for sum the row
	int rowCounter=1;	//the row for forword the next level without come back 
	for (int column = 0; column < s; column++) {		//the tecnic is fix column by column
		for (int row = rowCounter; row < s; row++) {	// and get inside to relevant row
			if (column<row )  {
				divisor = M[row * s + column] /(M[column * s + column]);
				cout << divisor << "\n";
				sumRow(s, M, B,row,column, divisor);//clac row function

				 
				//M[row * s + column] = -divisor * M[rowCounter*s+column];
				//cout << "(" << row << "," << column << ")="<< M[row* s + column]<<"\n";
			}
		}
		rowCounter++; //gump to start from the relevant row
	}
}

void Method2Solver::sumRow(int s, double*& M, double*& B, int row, int column,int divisor) {

};