#pragma once
#include <iostream>
using namespace std;

bool isSingular(double* matrix, int n);
double CalcDeterminant(double* matrix, int n);
bool isZeroVector(double* b, int n);
bool MultiMatrixWithVector(int size, double* mat, double* vec);