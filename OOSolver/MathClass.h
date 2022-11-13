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
	bool isInputInvalid();
	void PrintData();

private:
	bool singular;
	bool zeroVector;
};

