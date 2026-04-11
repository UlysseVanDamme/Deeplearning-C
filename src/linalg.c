#include "probability.h"
#include <stdio.h>
#include <stdlib.h>
#include <linalg.h>
#include "vector.h"

QR_result QR_decomposition(Matrix* A) {
    // Calculates QR decomposition using householder transformations (pain to implement)
    int m = A->rows;
    int n = A->cols;

    Matrix* R = copy_matrix(A);
    Matrix* Q = identity_matrix(m);
    for (int i = 0; i < n; i++) {
        int len = m - i;
        Matrix* x = make_empty_matrix(len, 1);

        for (int j = 0; j < len; j++) {
            set_value(x, j, 0, get_value(R, i + j, i));
        }
        float norm_x = p_norm(x, 2);
        float alpha = -sign(get_value(x, 0, 0)) * norm_x;

        Matrix* v = copy_matrix(x);
        set_value(v, 0, 0, get_value(v, 0, 0) - alpha);
        float v_dot = dot_product(v, v);

        for (int j = i; j < n; j++) {
            Matrix* u = make_empty_matrix(len, 1);

            for (int k = 0; k < len; k++) {
                set_value(u, k, 0, get_value(R, i + k, j));
            }
            float uv = dot_product(u, v);
            Matrix* temp = copy_matrix(v);
            matrix_scale(temp, 2.0f * uv / v_dot);

            Matrix* new_u = matrix_sub(u, temp);
            for (int k = 0; k < len; k++) {
                set_value(R, i + k, j, get_value(new_u, k, 0));
            }
            free_matrix(u);
            free_matrix(temp);
            free_matrix(new_u);
        }
        for (int j = 0; j < m; j++) {
            Matrix* u = make_empty_matrix(len, 1);
            for (int k = 0; k < len; k++) {
                set_value(u, k, 0, get_value(Q, j, i + k));
            }
            float uv = dot_product(u, v);

            Matrix* temp = copy_matrix(v);
            matrix_scale(temp, 2.0f * uv / v_dot);
            Matrix* new_u = matrix_sub(u, temp);

            for (int k = 0; k < len; k++) {
                set_value(Q, j, i + k, get_value(new_u, k, 0));
            }
            free_matrix(u);
            free_matrix(temp);
            free_matrix(new_u);
        }
        free_matrix(x);
        free_matrix(v);
    }
    QR_result result;
    result.Q = Q;
    result.R = R;
    return result;
}

Matrix* backward_substitution(Matrix* U, Matrix* B) {
    Matrix* X = make_empty_matrix(U->cols, 1);
    for (int j = U->rows - 1; j >= 0; j--) {
        float val = get_value(U, j, j);
        if (val == 0) {
            return NULL;
        }
        float xj = get_value(B, j, 0) / val;
        set_value(X, j, 0, xj);
        for (int i = 0; i < j; i++) {
            set_value(B, i, 0, get_value(B, i, 0) - get_value(U, i, j)*xj);
        }
    }
    return X;
}

// eigenvalues and eigenvectors

float power_iteration(Matrix* a, int iterations) {
    srand(time(NULL));

    if (!is_square(a)) {
        printf("Matrix is not square\n");
        return 0;
    }

    int n = a->rows;

    Matrix* x = make_empty_matrix(n, 1);
    for (int i = 0; i < n; i++) {
        set_value(x, i, 0, (float)(rand() % 10 + 1));
    }

    float lambda = 0;

    for (int it = 0; it < iterations; it++) {
        Matrix* y = matrix_multiply(a, x);
        lambda = max_norm(y);
        x = y;

        matrix_scale(x, 1.0f / max_norm(x));
    }

    free_matrix(x);
    return lambda;
}

