#pragma once
class MathClass
{
public:
	int probSize;
	double* M;
	double* b;

	MathClass();
	~MathClass();
	bool LoadInput();
	void PrintMatrix();
	void PrintVector(double* v, int n);
};

