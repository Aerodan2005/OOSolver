#include "MathClass.h"
#include <iostream>
#include <fstream>
using namespace std;
MathClass::MathClass()
{
	ifstream inFile;
	inFile.open("Input.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	inFile >> a;
	M = new double[a * a];
	b = new double[a];

	for(int i = 0; i < a*a ; i++)
	{
		inFile >> M[i];
	}

	for (int i = 0; i < a; i++)
	{
		inFile >> b[i];
	}

	inFile.close();
}

void MathClass::PrintMatrix()
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)

			// Prints ' ' if j != n-1 else prints '\n'         
			cout << M[i * a + j] << " \n"[j == a - 1];
}

bool MathClass::isSingular()
{
	bool flg = false;

	return flg;
}

