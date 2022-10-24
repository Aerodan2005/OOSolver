#pragma once
class MathClass
{
public:
	int a;
	double* M;
	double* b;

	MathClass();
	void PrintMatrix();
	bool isSingular();
};

