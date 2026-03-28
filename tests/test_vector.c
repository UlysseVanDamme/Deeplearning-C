#include <stdio.h>
#include "vector.h"

#define ASSERT_EQ(actual, expected) \
    if ((actual) != (expected)) { \
        printf("FAIL: expected %.2f, got %.2f\n", (expected), (actual)); \
    } else { \
        printf("PASS\n"); \
    }

void test_dot_product_basic() {
    printf("\nTest: dot product (basic)\n");

    Matrix* v1 = make_empty_matrix(3, 1);
    Matrix* v2 = make_empty_matrix(3, 1);

    set_value(v1, 0, 0, 1.0f);
    set_value(v1, 1, 0, 2.0f);
    set_value(v1, 2, 0, 3.0f);

    set_value(v2, 0, 0, 4.0f);
    set_value(v2, 1, 0, 5.0f);
    set_value(v2, 2, 0, 6.0f);

    float result = dot_product(v1, v2);

    // 1*4 + 2*5 + 3*6 = 32
    ASSERT_EQ(result, 32.0f);

    free_matrix(v1);
    free_matrix(v2);
}

void test_dot_product_with_zero() {
    printf("\nTest: dot product (with zeros)\n");

    Matrix* v1 = make_empty_matrix(3, 1);
    Matrix* v2 = make_empty_matrix(3, 1);

    set_value(v1, 0, 0, 0.0f);
    set_value(v1, 1, 0, 0.0f);
    set_value(v1, 2, 0, 0.0f);

    set_value(v2, 0, 0, 5.0f);
    set_value(v2, 1, 0, 10.0f);
    set_value(v2, 2, 0, 15.0f);

    float result = dot_product(v1, v2);

    ASSERT_EQ(result, 0.0f);

    free_matrix(v1);
    free_matrix(v2);
}

void test_dot_product_negative() {
    printf("\nTest: dot product (negative values)\n");

    Matrix* v1 = make_empty_matrix(3, 1);
    Matrix* v2 = make_empty_matrix(3, 1);

    set_value(v1, 0, 0, -1.0f);
    set_value(v1, 1, 0, 2.0f);
    set_value(v1, 2, 0, -3.0f);

    set_value(v2, 0, 0, 4.0f);
    set_value(v2, 1, 0, -5.0f);
    set_value(v2, 2, 0, 6.0f);

    float result = dot_product(v1, v2);

    // (-1*4) + (2*-5) + (-3*6) = -4 -10 -18 = -32
    ASSERT_EQ(result, -32.0f);

    free_matrix(v1);
    free_matrix(v2);
}

int main() {
    test_dot_product_basic();
    test_dot_product_with_zero();
    test_dot_product_negative();
    return 0;
}