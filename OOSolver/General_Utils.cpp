#include "General_Utils.h"

void load_file() {
	//insert size for text file
	
};

bool isSingular(double* matrix, int n)
{
    double det;
    det = CalcDeterminant(matrix, n);
    return det == 0;
}

double CalcDeterminant(double *matrix, int n)
{
    double det = 0;
    double submatrix[9];
    if (n == 2)
        return ((matrix[0] * matrix[3]) - (matrix[1] * matrix[2]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            int subj = 0;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == x)
                    { 
                        continue; 
                    }
                    submatrix[subi*(n-1) + subj] = matrix[i*n + j];
                    subj++;
                }
                if (subj == n-1)
                {                 
                    subi++;
                    subj = 0;
                }
            }
            det = det + (pow(-1, x) * matrix[x] * CalcDeterminant(submatrix, n - 1));
        }
    }
    //std::cout << "Determinant is " << det << std::endl;
    return det;
}
