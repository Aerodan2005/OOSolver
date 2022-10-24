#pragma once
class MathClass
{
public:
	int probSize;
	double* M;
	double* b;

	MathClass();
	~MathClass();
	bool LoadMatrix();
	void PrintMatrix();
	bool isSingular();
};

