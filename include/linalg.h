#ifndef LINALG_H
#define LINALG_H
#include "vector.h"

typedef struct {
    Matrix* Q;
    Matrix* R;
} QR_result;

void LU_decomposition(Matrix* a, Matrix* L, Matrix* U);

QR_result QR_decomposition(Matrix* a); // Using householder transformation

#endif