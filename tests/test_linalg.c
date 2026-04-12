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


int main() {
    test_QR_factorization();
    test_poweriteration();
    test_LU_decomposition();
    test_lineair_solver();
    return 0;
}