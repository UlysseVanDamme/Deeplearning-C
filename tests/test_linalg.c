#include <stdio.h>
#include <stdlib.h>
#include "linalg.h"

#define ASSERT_EQ(actual, expected) \
    if ((actual) != (expected)) { \
        printf("FAIL: expected %.2f, got %.2f\n", (expected), (actual)); \
    } else { \
        printf("PASS\n"); \
    }

#define ASSERT_LT(actual, expected) \
if ((actual) >= (expected)) { \
    printf("FAIL: %.2f is larger than %.2f\n", (expected), (actual)); \
} else { \
    printf("PASS\n"); \
}

void test_QR_factorization() {
    // 1 -1.0 1
    // 1 -0.5 0.25
    // 1 0.0  0.0
    // 1 0.5  0.25
    // 1 1.0  1

    Matrix* A = make_empty_matrix(5, 3);
    set_value(A, 0, 0, 1);
    set_value(A, 1, 0, 1);
    set_value(A, 2, 0, 1);
    set_value(A, 3, 0, 1);
    set_value(A, 4, 0, 1);

    set_value(A, 0, 1, -1.0);
    set_value(A, 1, 1, -0.5);
    set_value(A, 2, 1, 0);
    set_value(A, 3, 1, 0.5);
    set_value(A, 4, 1, 1);

    set_value(A, 0, 2, 1.0);
    set_value(A, 1, 2, 0.25);
    set_value(A, 2, 2, 0);
    set_value(A, 3, 2, 0.25);
    set_value(A, 4, 2, 1);

    QR_result result = QR_decomposition(A);
    free_matrix(A);
}

void test_poweriteration() {
    Matrix* A = make_empty_matrix(2, 2);

    set_value(A, 0, 0, 1.5);
    set_value(A, 1, 0, 0.5);
    set_value(A, 0, 1, 0.5);
    set_value(A, 1, 1, 1.5);

    float result = power_iteration(A, 9);

    ASSERT_LT(result - 2, 0.01);
    free_matrix(A);
}

void test_rayleigh_quotient_iteration() {
    Matrix* B = make_empty_matrix(2, 2);

    set_value(B, 0, 0, 1.5);
    set_value(B, 1, 0, 0.5);
    set_value(B, 0, 1, 0.5);
    set_value(B, 1, 1, 1.5);
    float result = rayleigh_quotient_iteration(B, 3);

    ASSERT_LT(result - 2, 0.01);
    free_matrix(B);
}

void test_LU_decomposition() {
    Matrix* A = make_empty_matrix(3, 3);
    set_value(A, 0, 0, 2);
    set_value(A, 0, 1, 4);
    set_value(A, 0, 2, -2);
    set_value(A, 1, 0, 4);
    set_value(A, 1, 1, 9);
    set_value(A, 1, 2, -3);
    set_value(A, 2, 0, -2);
    set_value(A, 2, 1, -3);
    set_value(A, 2, 2, 7);

    LU_result result = LU_decomposition(A);

    Matrix* LU = matrix_multiply(result.L, result.U);

    ASSERT_EQ(get_value(LU, 0, 0), 2.0f);
    ASSERT_EQ(get_value(LU, 0, 1), 4.0f);
    ASSERT_EQ(get_value(LU, 0, 2), -2.0f);
    ASSERT_EQ(get_value(LU, 1, 0), 4.0f);
    ASSERT_EQ(get_value(LU, 1, 1), 9.0f);
    ASSERT_EQ(get_value(LU, 1, 2), -3.0f);
    ASSERT_EQ(get_value(LU, 2, 0), -2.0f);
    ASSERT_EQ(get_value(LU, 2, 1), -3.0f);
    ASSERT_EQ(get_value(LU, 2, 2), 7.0f);

    free_matrix(A);
    free_matrix(result.L);
    free_matrix(result.U);
    free_matrix(LU);
}

void test_lineair_solver() {
    Matrix* A = make_empty_matrix(3, 3);
    set_value(A, 0, 0, 2);
    set_value(A, 0, 1, 4);
    set_value(A, 0, 2, -2);
    set_value(A, 1, 0, 4);
    set_value(A, 1, 1, 9);
    set_value(A, 1, 2, -3);
    set_value(A, 2, 0, -2);
    set_value(A, 2, 1, -3);
    set_value(A, 2, 2, 7);

    Matrix* B = make_empty_matrix(3, 1);
    set_value(B, 0, 0, 2);
    set_value(B, 1, 0, 8);
    set_value(B, 2, 0, 10);

    Matrix* X = lineair_solver(A, B);

    ASSERT_EQ(get_value(X, 0, 0), -1.0f);
    ASSERT_EQ(get_value(X, 1, 0), 2.0f);
    ASSERT_EQ(get_value(X, 2, 0), 2.0f);

    free_matrix(X);
    free_matrix(A);
    free_matrix(B);
}


void test_cholesky_factorization() {
    // A = [4 12 -16; 12 37 -43; -16 -43 98] (symmetric positive definite)
    // Expected L = [2 0 0; 6 1 0; -8 5 3]
    Matrix* A = make_empty_matrix(3, 3);
    set_value(A, 0, 0, 4);
    set_value(A, 0, 1, 12);
    set_value(A, 0, 2, -16);
    set_value(A, 1, 0, 12);
    set_value(A, 1, 1, 37);
    set_value(A, 1, 2, -43);
    set_value(A, 2, 0, -16);
    set_value(A, 2, 1, -43);
    set_value(A, 2, 2, 98);

    Matrix* L = cholesky_factorization(A);

    ASSERT_EQ(get_value(L, 0, 0), 2.0f);
    ASSERT_EQ(get_value(L, 1, 0), 6.0f);
    ASSERT_EQ(get_value(L, 1, 1), 1.0f);
    ASSERT_EQ(get_value(L, 2, 0), -8.0f);
    ASSERT_EQ(get_value(L, 2, 1), 5.0f);
    ASSERT_EQ(get_value(L, 2, 2), 3.0f);

    // Verify L * L^T = A
    Matrix* Lt = transpose(L);
    Matrix* LLt = matrix_multiply(L, Lt);

    ASSERT_EQ(get_value(LLt, 0, 0), 4.0f);
    ASSERT_EQ(get_value(LLt, 1, 1), 37.0f);
    ASSERT_EQ(get_value(LLt, 2, 2), 98.0f);
    ASSERT_EQ(get_value(LLt, 0, 1), 12.0f);
    ASSERT_EQ(get_value(LLt, 1, 2), -43.0f);

    free_matrix(A);
    free_matrix(L);
    free_matrix(Lt);
    free_matrix(LLt);
}

int main() {
    test_QR_factorization();
    test_poweriteration();
    test_rayleigh_quotient_iteration();
    test_LU_decomposition();
    test_lineair_solver();
    test_cholesky_factorization();
    return 0;
}