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

Matrix* Mmul(Matrix* a, Matrix* b);
Matrix* Madd(Matrix* a, Matrix* b);

Matrix* transpose(Matrix* a);

#endif