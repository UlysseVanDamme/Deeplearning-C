#ifndef LINALG_H
#define LINALG_H
#include "vector.h"

typedef struct {
    Matrix* Q;
    Matrix* R;
} QR_result;

typedef struct {
    Matrix* L;
    Matrix* U;
} LU_result;

LU_result LU_decomposition(Matrix* A); // TODO

Matrix* lineair_solver(Matrix*a, Matrix* b); // TODO

QR_result QR_decomposition(Matrix* a); // Using householder transformation

Matrix* backward_substitution(Matrix* U, Matrix* B);
Matrix* forward_substitution(Matrix* L, Matrix* B);

// Eigenvalues and Eigenvectors

float power_iteration(Matrix* a, int iterations); // finds greatest eigenvalue

float rayleigh_quotient_iteration(Matrix* a, int iterations); // finds greatest eigenvalue

#endif