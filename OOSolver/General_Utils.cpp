#include "General_Utils.h"

void load_file(int* a, double*& m, double*& b) {
	//insert size for text file
	*a = 5;
	int x = *a;
	m = new double[x*x];
	b = new double[x];

	m[0] = 6.7;
	m[1] = 3.7;
	m[3] = 5;
	b[0] = 3;
	b[1] = 33.3;
	b[2] = 56.3;
	b[3] = 2;

};
