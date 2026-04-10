#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    float* data;
} Matrix;

Matrix* make_matrix(int rows, int cols);
Matrix* make_empty_matrix(int rows, int cols);

float get_value(Matrix* m, int row, int col);
void set_value(Matrix* m, int row, int col, float number);

void free_matrix(Matrix* m);
void print_matrix(Matrix* m);

Matrix* matrix_multiply(Matrix* a, Matrix* b);
Matrix* matrix_add(Matrix* a, Matrix* b);
Matrix* matrix_sub(Matrix* a, Matrix* b);

void matrix_scale(Matrix* a, float b);

int is_square(Matrix* a);
float trace(Matrix* a);

Matrix* transpose(Matrix* a);

Matrix* identity_matrix(int size);

Matrix* copy_matrix(Matrix* m);

#endif