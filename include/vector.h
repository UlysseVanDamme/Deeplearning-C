#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"


int is_vector(Matrix* vector);

float dot_product(Matrix* v1, Matrix* v2);

float p_norm(Matrix* vector, int p);

Matrix* get_row(Matrix* matrix, int row);
Matrix* get_col(Matrix* matrix, int col);

void set_row(Matrix* matrix, Matrix* r, int row);
void set_col(Matrix* matrix, Matrix* c, int col);


#endif