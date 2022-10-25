#include "MathClass.h"
#include <iostream>
#include <fstream>
using namespace std;

MathClass::MathClass() {
	M = nullptr;
	b = nullptr;
}

MathClass::~MathClass()
{
	if (M != nullptr) delete[] M;
	if (b != nullptr) delete[] b;
}

bool MathClass::LoadInput() {
	ifstream inFile;
	inFile.open("Input.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file";
		exit(EXIT_FAILURE);
	}

	inFile >> probSize;
	bool isPositive = probSize > 0;
	if (!isPositive)
	{
		cout << "Dimension size should be a positive integer.";
		exit(EXIT_FAILURE);
	}

	M = new double[probSize * probSize];
	b = new double[probSize];

	for (int i = 0; i < probSize * probSize; i++)
	{
		inFile >> M[i];
	}

	for (int i = 0; i < probSize; i++)
	{
		inFile >> b[i];
	}

	inFile.close();
	return true;
}

void MathClass::PrintMatrix()
{
	for (int i = 0; i < probSize; i++)
		for (int j = 0; j < probSize; j++)
			// Prints ' ' if j != n-1 else prints '\n'         
			cout << M[i * probSize + j] << " \n"[j == probSize - 1];
}

void MathClass::PrintVector(double* v, int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

