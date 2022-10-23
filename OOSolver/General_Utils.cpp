#include "General_Utils.h"

void load_file(int* a, double*& m, double*& b) {
	//insert size fro text file
	*a = 5;
	int x = *a;
	m = new double[x*x];
	b = new double[x];
};
