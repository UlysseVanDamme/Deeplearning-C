#include <stdio.h>
#include "matrix.h"

#define ASSERT_EQ(actual, expected) \
    if ((actual) != (expected)) { \
        printf("FAIL: expected %.2f, got %.2f\n", (expected), (actual)); \
    } else { \
        printf("PASS\n"); \
    }

void test_set_get() {
    printf("Test: set/get\n");

    Matrix* m = make_empty_matrix(2, 2);

    set_value(m, 0, 0, 1.0f);
    set_value(m, 0, 1, 2.0f);
    set_value(m, 1, 0, 3.0f);
    set_value(m, 1, 1, 4.0f);

    ASSERT_EQ(get_value(m, 0, 0), 1.0f);
    ASSERT_EQ(get_value(m, 0, 1), 2.0f);
    ASSERT_EQ(get_value(m, 1, 0), 3.0f);
    ASSERT_EQ(get_value(m, 1, 1), 4.0f);

    free_matrix(m);
}

void test_zero_init() {
    printf("\nTest: zero initialization\n");

    Matrix* m = make_empty_matrix(2, 2);

    ASSERT_EQ(get_value(m, 0, 0), 0.0f);
    ASSERT_EQ(get_value(m, 1, 1), 0.0f);

    free_matrix(m);
}

void test_overwrite() {
    printf("\nTest: overwrite values\n");

    Matrix* m = make_empty_matrix(1, 1);

    set_value(m, 0, 0, 5.0f);
    set_value(m, 0, 0, 10.0f);

    ASSERT_EQ(get_value(m, 0, 0), 10.0f);

    free_matrix(m);
}

void test_print() {
    printf("\nTest: print matrix\n");

    Matrix* m = make_empty_matrix(2, 2);

    set_value(m, 0, 0, -2);
    set_value(m, 0, 1, 4);
    set_value(m, 1, 1, 5);

    print_matrix(m);

    free_matrix(m);
}

void test_add() {
    printf("\nTest: add matrix\n");

    Matrix* m1 = make_empty_matrix(2, 2);

    set_value(m1, 0, 0, -2);
    set_value(m1, 0, 1, 4);
    set_value(m1, 1, 1, 5);

    Matrix* m2 = make_empty_matrix(2, 2);

    set_value(m2, 0, 0, -4);
    set_value(m2, 0, 1, -2);
    set_value(m2, 1, 1, 4);

    Matrix* m3 = Madd(m1, m2);

    ASSERT_EQ(get_value(m3, 0, 0), -6.0f);
    ASSERT_EQ(get_value(m3, 0, 1), 2.0f);
    ASSERT_EQ(get_value(m3, 1, 0), 0.0f);
    ASSERT_EQ(get_value(m3, 1, 1), 9.0f);

    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);

}

void test_multiply() {
    printf("\nTest: matrix multiplication\n");

    Matrix* A = make_empty_matrix(2, 3);
    set_value(A, 0, 0, 1);
    set_value(A, 0, 1, 2);
    set_value(A, 0, 2, 3);
    set_value(A, 1, 0, 4);
    set_value(A, 1, 1, 5);
    set_value(A, 1, 2, 6);

    Matrix* B = make_empty_matrix(3, 2);
    set_value(B, 0, 0, 7);
    set_value(B, 0, 1, 8);
    set_value(B, 1, 0, 9);
    set_value(B, 1, 1, 10);
    set_value(B, 2, 0, 11);
    set_value(B, 2, 1, 12);

    Matrix* C = Mmul(A, B); 

    ASSERT_EQ(get_value(C, 0, 0), 58.0f);  
    ASSERT_EQ(get_value(C, 0, 1), 64.0f); 
    ASSERT_EQ(get_value(C, 1, 0), 139.0f);
    ASSERT_EQ(get_value(C, 1, 1), 154.0f); 

    print_matrix(C);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

void test_transpose() {
    printf("\nTest: transpose matrix\n");

    Matrix* A = make_empty_matrix(2, 3);

    set_value(A, 0, 0, 1);
    set_value(A, 0, 1, 2);
    set_value(A, 0, 2, 3);
    set_value(A, 1, 0, 4);
    set_value(A, 1, 1, 5);
    set_value(A, 1, 2, 6);

    Matrix* transposed_matrix = transpose(A);

    ASSERT_EQ(get_value(transposed_matrix, 0, 0), 1.0f);
    ASSERT_EQ(get_value(transposed_matrix, 0, 1), 4.0f);
    ASSERT_EQ(get_value(transposed_matrix, 1, 0), 2.0f);
    ASSERT_EQ(get_value(transposed_matrix, 1, 1), 5.0f);
    ASSERT_EQ(get_value(transposed_matrix, 2, 0), 3.0f);
    ASSERT_EQ(get_value(transposed_matrix, 2, 1), 6.0f);

    print_matrix(transposed_matrix);

    free(A);
    free(transposed_matrix);
}


int main() {
    test_set_get();
    test_zero_init();
    test_overwrite();
    test_print();
    test_add();
    test_multiply();
    test_transpose();

    return 0;
}