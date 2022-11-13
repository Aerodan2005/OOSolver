//  Gaussian Elimination solver
#include "Method2Solver.h"

bool Method2Solver::solverProcedure() {
	int S = mc->probSize; // this is a local var for matrix size
	double*& M = mc->M;  //  this is a local var for matrix 
	double*& b = mc->b; //   this is a local var for vector

	partialPivoting(S, M, b);
	calcPivot(S, M, b, solution);
	DisplayResult(solution, S);
	if (solution != nullptr) delete[] solution;
	return true;
}

void Method2Solver::partialPivoting(int s, double*& M, double*& b) {
	double divisor;	//the divider number for sum the row	
	for (int row = 1; row < s; row++) {	//the tecnic is fix column by column
		for (int rowCounter = row; rowCounter < s; rowCounter++) {	// and get inside to relevant row
			divisor = M[(rowCounter)*s + (row - 1)] / (M[(row - 1) * s + (row - 1)]);
			for (int column = 0; column < s; column++) {
				M[rowCounter * s + column] -= divisor * M[(row - 1) * s + column];
			}
			b[rowCounter] -= divisor * b[row - 1];
		}
	}
}

void Method2Solver::calcPivot(int Size, double*& M, double*& b, double*& result) {
	result = new double[Size] {0};
	double sum;
	for (int row = Size - 1; row >= 0; row--) {					// start from last row
		sum = 0;
		for (int column = row + 1; column < Size; column++) {   // check if have a relevant varible on right side of the matrix
			sum += result[column] * M[Size * row + column];
		}
		result[row] = ((b[row] - sum) / M[Size * row + row]);
	}
};
