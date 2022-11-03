#pragma once
#include"General_Utils.h"

class MathClass
{
public:
	int probSize;
	double* M;
	double* b;

	MathClass();
	~MathClass();
	bool LoadInput();
	bool isInputValid();
	void PrintMatrix();
	void PrintVector(double* v, int n);
	void PrintData();

private:
	bool singular;
	bool zeroVector;
};

