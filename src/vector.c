#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

int is_vector(Matrix* vector) {
    return vector->cols == 1 || vector->rows == 1;
}

float dot_product(Matrix* v1, Matrix* v2) {
    if (!is_vector(v1) || !is_vector(v2)) {
        printf("Not a vector");
        return 0;
    }
    float result = get_value(matrix_multiply(transpose(v1), v2), 0, 0);
    return result;
}

float p_norm(Matrix* vector, int p) {
    float sum = 0;

    for (int i = 0; i < vector->rows; i++) {
        float x = get_value(vector, i, 0);
        sum += powf(fabsf(x), p);
    }

    return powf(sum, 1.0f / p);
}

float max_norm(Matrix* vector) {
    if (!is_vector(vector)) {
        printf("Not a vector");
        return 0;
    }
    float max = 0;
    for (int i = 0; i < vector->rows; i++) {
        float val = fabsf(get_value(vector, i, 0));
        if (val > max) {
            max = val;
        }
    }
    return max;
}

Matrix* get_row(Matrix* matrix, int row) {
    if (row > (matrix->rows - 1)) {
        printf("index out of bounds");
        return NULL;
    }
    Matrix* result = make_matrix(1, matrix->cols);
    for (int i = 0; i < matrix->cols; i++) {
        set_value(result, 0, i, get_value(matrix, row, i));
    }
    return result;
}

Matrix* get_col(Matrix* matrix, int col) {
    if (col > (matrix->cols - 1)) {
        printf("index out of bounds");
        return NULL;
    }
    Matrix* result = make_matrix(matrix->rows, 1);
    for (int i = 0; i < matrix->rows; i++) {
        set_value(result, i, 0, get_value(matrix, i, col));
    }
    return result;
}

void set_row(Matrix* matrix, Matrix* r, int row) {
    if (!is_vector(r)) {
        printf("Not a vector\n");
        return 0;
    }
    if (row > (matrix->rows - 1)) {
        printf("index out of bounds\n");
        return NULL;
    }
    for (int i = 0; i < matrix->cols; i++) {
        set_value(matrix, row, i, get_value(r, 0, i));
    }
}

void set_col(Matrix* matrix, Matrix* c, int col) {
    if (!is_vector(c)) {
        printf("Not a vector");
        return 0;
    }
    if (col > (matrix->cols - 1)) {
        printf("index out of bounds");
        return NULL;
    }
    for (int i = 0; i < matrix->rows; i++) {
        set_value(matrix, i, col, get_value(c, i, 0));
    }
}
