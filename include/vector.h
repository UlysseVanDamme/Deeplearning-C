#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

int is_vector(Matrix* vector);

float dot_product(Matrix* v1, Matrix* v2);

float p_norm(Matrix* vector, int p);

#endif