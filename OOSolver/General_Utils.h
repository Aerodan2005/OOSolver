#pragma once
#include <iostream>
using namespace std;

bool isSingular(double* matrix, int n);
double CalcDeterminant(double* matrix, int n);
bool isZeroVector(double* b, int n);
bool Multi_MatrixWithVector(int size, double* mat, double* vec,double *& result );
void DisplayResult(double* vec, int size);
void printMatrix(int size, double* mat);