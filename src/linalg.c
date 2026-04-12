#include <stdio.h>
#include <stdlib.h>
#include <linalg.h>
#include <time.h>
#include "vector.h"
#include "probability.h"

LU_result LU_decomposition(Matrix* A) {
    int n = A->cols;
    Matrix* U = copy_new_matrix(A);                                                                                                                                                   
    Matrix* L = identity_matrix(n);
    for (int k = 0; k < n; k++) {                                                                                                                                                     
        Matrix* M  = identity_matrix(n);
        Matrix* Lj = identity_matrix(n);                                                                                                                                              
        float a_kk = get_value(U, k, k);
        for (int j = k + 1; j < n; j++) {                                                                                                                                             
            float m_jk = get_value(U, j, k) / a_kk;
            set_value(M,  j, k, -m_jk);                                                                                                                                               
            set_value(Lj, j, k,  m_jk);                                                                                                                                               
        }
        Matrix* F = matrix_multiply(M, U);                                                                                                                                            
        copy_matrix(F, U);
        free_matrix(F);                                                                                                                                                               
        Matrix* B = matrix_multiply(L, Lj);                                                                                                             
        copy_matrix(B, L);                                                                                                                                                            
        free_matrix(B);                                                                                                                                                               
        free_matrix(M);                                                                                                                                                               
        free_matrix(Lj);
    }
    LU_result result;
    result.L = L;
    result.U = U;
    return result;                                                                                                                                                                    
}

Matrix* lineair_solver(Matrix*a, Matrix* b) {
    LU_result LU = LU_decomposition(a);
    Matrix* y = forward_substitution(LU.L, b);
    Matrix* x = backward_substitution(LU.U, y);
    free_matrix(y);
    return x;
}


QR_result QR_decomposition(Matrix* A) {
    // Calculates QR decomposition using householder transformations (pain to implement)
    int m = A->rows;
    int n = A->cols;

    Matrix* R = copy_new_matrix(A);
    Matrix* Q = identity_matrix(m);
    for (int i = 0; i < n; i++) {
        int len = m - i;
        Matrix* x = make_empty_matrix(len, 1);

        for (int j = 0; j < len; j++) {
            set_value(x, j, 0, get_value(R, i + j, i));
        }
        float norm_x = p_norm(x, 2);
        float alpha = -sign(get_value(x, 0, 0)) * norm_x;

        Matrix* v = copy_new_matrix(x);
        set_value(v, 0, 0, get_value(v, 0, 0) - alpha);
        float v_dot = dot_product(v, v);

        for (int j = i; j < n; j++) {
            Matrix* u = make_empty_matrix(len, 1);

            for (int k = 0; k < len; k++) {
                set_value(u, k, 0, get_value(R, i + k, j));
            }
            float uv = dot_product(u, v);
            Matrix* temp = copy_new_matrix(v);
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

            Matrix* temp = copy_new_matrix(v);
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

Matrix* forward_substitution(Matrix* L, Matrix* B) {
    Matrix* X = make_empty_matrix(L->cols, 1);
    for (int j = 0; j < L->rows; j++) {
        float val = get_value(L, j, j);
        if (val == 0) {
            return NULL;
        }
        float xj = get_value(B, j, 0) / val;
        set_value(X, j, 0, xj);
        for (int i = j + 1; i < L->rows; i++) {
            set_value(B, i, 0, get_value(B, i, 0) - get_value(L, i, j)*xj);
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
        free_matrix(x);
        x = y;

        matrix_scale(x, 1.0f / max_norm(x));
    }

    free_matrix(x);
    return lambda;
}

float rayleigh_quotient_iteration(Matrix* a, int iterations) {
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
    float sigma = 0.0f;
    for (int it = 0; it < iterations; it++) {
        Matrix* Ax = matrix_multiply(a, x);
        sigma = dot_product(x, Ax) / dot_product(x, x);

        Matrix* I = identity_matrix(n);
        matrix_scale(I, sigma);
        Matrix* A_shifted = matrix_sub(a, I);
        Matrix* x_new = matrix_multiply(A_shifted, x);

        free_matrix(x);
        free_matrix(Ax);
        free_matrix(I);
        free_matrix(A_shifted);

        x = x_new;
        matrix_scale(x, 1.0f / max_norm(x));
    }

    free_matrix(x);
    return sigma;
}