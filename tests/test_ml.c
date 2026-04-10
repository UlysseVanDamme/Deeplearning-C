#include <stdio.h>
#include <stdlib.h>
#include "machine_learning.h"

#define ASSERT_EQ(actual, expected) \
    if ((actual) != (expected)) { \
        printf("FAIL: expected %.2f, got %.2f\n", (expected), (actual)); \
    } else { \
        printf("PASS\n"); \
    }


void test_lineair_least_squares() {

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

    print_matrix(A);

    Matrix* y = make_empty_matrix(5, 1); 
    set_value(y, 0, 0, 1.0);
    set_value(y, 1, 0, 0.5);
    set_value(y, 2, 0, 0);
    set_value(y, 3, 0, 0.5);
    set_value(y, 4, 0, 2.0);

    Matrix* x = lineair_least_squares(A, y);

    print_matrix(x);
    free_matrix(x);
    free_matrix(A);
    free_matrix(y);
}

int main() {
    test_lineair_least_squares();
    return 0;
}