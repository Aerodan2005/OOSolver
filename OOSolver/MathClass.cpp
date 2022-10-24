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
	if (M !=nullptr)
		delete[] M;
	if (b != nullptr)
		delete[] b;
}

bool MathClass::LoadMatrix() {
	ifstream inFile;
	inFile.open("Input.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file";
		return false;
	}
	inFile >> probSize;
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

bool MathClass::isSingular()
{
	bool flg = false;

	return flg;
}

