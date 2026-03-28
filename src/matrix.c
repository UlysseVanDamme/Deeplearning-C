#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* make_matrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    if (m == NULL) {
        printf("Matrix memory allocation failed");
        return NULL;
    }
    m->cols = cols;
    m->rows = rows;

    m->data = malloc(sizeof(float) * rows * cols);
    if (m->data == NULL) {
        printf("Matrix data allocation failed");
        return NULL;
    }
    return m;
}

Matrix* make_empty_matrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    if (m == NULL) {
        printf("Matrix memory allocation failed");
        return NULL;
    }
    m->cols = cols;
    m->rows = rows;

    m->data = calloc(rows * cols, sizeof(float));
    if (m->data == NULL) {
        printf("Matrix data allocation failed");
        return NULL;
    }
    return m;
}

float get_value(Matrix* m, int row, int col) {
    if (col > (m->cols - 1) || row > (m->rows - 1)) {
        printf("%s", "index out of bounds");
        return 0;
    }
    if (m == NULL) {
        printf("%s", "matrix not defined");
        return 0;
    }
    float result =  m->data[row * m->cols + col];
    return result;
}

void set_value(Matrix* m, int row, int col, float number) {
    if (col > (m->cols - 1) || row > (m->rows - 1)) {
        printf("%s", "index out of bounds");
        return;
    }
    if (m == NULL) {
        printf("%s", "matrix not defined");
        return;
    }
    m->data[row * m->cols + col] = number;
}

Matrix* matrix_add(Matrix* a, Matrix* b) {
    if (a->cols != b->cols || a->rows != b->rows) {
        printf("Matrices don't have same dimension");
        return NULL;
    }
    Matrix* result = make_matrix(a->cols, a->rows);
    for (int i = 0; i < a->cols; i++) {
        for (int j = 0; j < a->rows; j++) {
            set_value(result, i, j, get_value(a, i, j) + get_value(b, i, j));
        }
    }
    return result;
}

Matrix* matrix_multiply(Matrix* a, Matrix* b) {
    if (a->cols != b->rows) {
        printf("Matrix dimensions invalid for multiplication");
        return NULL;
    }
    Matrix* c = make_matrix(a->rows, b->cols);
    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            float sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += get_value(a, i, k) * get_value(b, k, j);
            }
            set_value(c, i, j, sum);
        }
    }
    return c;
}

Matrix* transpose(Matrix* a) {
    Matrix* result = make_matrix(a->cols, a->rows);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            set_value(result, j, i, get_value(a, i, j));
        }
    }
    return result;
}


float trace(Matrix* a) {
    if (!is_square(a)) {
        printf("not a square matrix");
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < a->cols;i++) {
        sum += get_value(a, i, i);
    }
    return sum;
}

int is_square(Matrix* a) {
    int isSq = (a->cols == a->rows);
    return isSq;
}

float frobenius_norm(Matrix* a) {
    int sum = 0;
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            sum += pow(get_value(a, i, j), 2);
        }
    }

    float res = sqrt(sum);
    return res;
}

void free_matrix(Matrix* ptr) {
    if (ptr != NULL) {
        free(ptr->data);
        free(ptr);
    }
}

void print_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        printf("| ");
        for (int j = 0; j < m->cols; j++) {
            printf("%6.2f ", m->data[i * m->cols + j]);
        }
        printf("|\n");
    }
    printf("\n");
}