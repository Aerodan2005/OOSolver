#pragma once
#include"General_Utils.h"

class MathClass
{
public:
	int probSize;
	double* M;
	double* b;
	bool singular;
	bool zeroVector;
	//double determinant;

	MathClass();
	~MathClass();
	bool LoadInput();
	void PrintMatrix();
	void PrintVector(double* v, int n);
	void PrintData();
};

