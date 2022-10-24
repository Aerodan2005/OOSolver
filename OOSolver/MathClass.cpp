#include "MathClass.h"
MathClass::MathClass()
{
	a = 3;
	int x = a;
	M = new double[x * x];
	b = new double[x];

	M[0] = 10;
	M[1] = 11;
	M[2] = 12;
	M[3] = 13;
	M[4] = 14;
	M[5] = 15;
	M[6] = 16;
	M[7] = 17;
	M[8] = 18;
	b[0] = 100;
	b[1] = 101;
	b[2] = 102;
}