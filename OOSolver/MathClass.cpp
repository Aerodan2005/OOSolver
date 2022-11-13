#include "MathClass.h"
#include "General_Utils.h"
#include <iostream>
#include <fstream>
using namespace std;

MathClass::MathClass() {
	M = nullptr;
	b = nullptr;
	probSize = 0;
	singular = false;
	zeroVector = false;
}

MathClass::~MathClass()
{
	if (M != nullptr) delete[] M;
	if (b != nullptr) delete[] b;
}

bool MathClass::LoadInput()
{
	ifstream inFile;
	inFile.open("Input.txt");
	if (!inFile.is_open()) exit(EXIT_FAILURE); // Unable to open file

	inFile >> probSize;
	bool isSizePositive = (probSize > 0);
	if (!isSizePositive) exit(EXIT_FAILURE); // Dimension size should be a positive integer

	M = new double[probSize * probSize];
	for (int i = 0; i < probSize * probSize; i++)
		inFile >> M[i];

	b = new double[probSize];
	for (int i = 0; i < probSize; i++)
		inFile >> b[i];

	inFile.close();
	return true;
}

bool MathClass::isInputInvalid()
{
	singular = isSingular(M, probSize);
	if (singular) cout << "Matrix is singular" << endl;

	zeroVector = isZeroVector(b, probSize);
	if (zeroVector) cout << "Vector is all zeros" << endl;

	return (singular || zeroVector);
}

void MathClass::PrintData()
{
	cout << endl << "Given matrix:" << endl;
	printMatrix(probSize, M);
	cout << endl << "Given vector:" << endl;
	printVec(probSize,b);
};
