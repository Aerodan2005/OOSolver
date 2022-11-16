//  Gaussian Elimination solver
#include "Method2Solver.h"

bool Method2Solver::solverProcedure() {
	int S = mc->probSize; // this is a local var for matrix size
	double* MM = new double[S* S];  //  this is a local var for matrix 
	double* bb = new double[S]; //   this is a local var for vector

	for (int i = 0; i < (S * S); i++)
		MM[i] = mc->M[i];
	for (int i = 0; i < S; i++)
		bb[i] = mc->b[i];

	partialPivoting(S, MM, bb);
	calcPivot(S, MM, bb, solution);
	DisplayResult(solution, S);
	if (solution != nullptr) delete[] solution;
	if (MM != nullptr) delete[] MM; // its needed??
	if (bb != nullptr) delete[] bb;

	return true;
}

void Method2Solver::partialPivoting(int s, double*& MM, double*& bb) {
	double divisor;	//the divider number for sum the row	
	for (int row = 1; row < s; row++) {	//the tecnic is fix column by column
		for (int rowCounter = row; rowCounter < s; rowCounter++) {	// and get inside to relevant row
			divisor = MM[(rowCounter)*s + (row - 1)] / (MM[(row - 1) * s + (row - 1)]);
			for (int column = 0; column < s; column++) {
				MM[rowCounter * s + column] -= divisor * MM[(row - 1) * s + column];
			}
			bb[rowCounter] -= divisor * bb[row - 1];
		}
	}
}

void Method2Solver::calcPivot(int Size, double*& MM, double*& bb, double*& result) {
	result = new double[Size] {0};
	double sum;
	for (int row = Size - 1; row >= 0; row--) {					// start from last row
		sum = 0;
		for (int column = row + 1; column < Size; column++) {   // check if have a relevant varible on right side of the matrix
			sum += result[column] * MM[Size * row + column];
		}
		result[row] = ((bb[row] - sum) / MM[Size * row + row]);
	}
};
