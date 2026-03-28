#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

int is_vector(Matrix* vector) {
    if (vector->cols != 1 || vector->rows != 1) {
        return 1;
    } else {
        return 0;
    }
}

float dot_product(Matrix* v1, Matrix* v2) {
    if (!is_vector(v1) || !is_vector(v2)) {
        printf("Not a vector");
        return 0;
    }
    float result = get_value(matrix_multiply(transpose(v1), v2), 0, 0);
}

float p_norm(Matrix* vector, int p) {
    if (!is_vector(vector)) {
        printf("Not a vector");
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < vector->rows; i++) {
        sum += pow(abs(get_value(vector, i, 0)), p);
    }
    float result = pow(sum, 1/p);
    return result;
}

float max_norm(Matrix* vector) {
    if (!is_vector(vector)) {
        printf("Not a vector");
        return 0;
    }
    float max = 0;
    for (int i = 0; i < vector->rows; i++) {
        float val = abs(get_value(vector, i, 0));
        if (val > max) {
            max = val;
        }
    }
    return max;
}
