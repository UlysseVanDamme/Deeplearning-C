#include <stdio.h>
#include <math.h>
#include "interpolation.h"
#include "linalg.h"

Matrix* monomial_interpolation(Matrix* x_nodes, Matrix* y_nodes) {
    return NULL;
}

float lagrange_interpolation(Matrix* x_nodes, Matrix* y_nodes, float x) {
    return 0.0f;
}

Matrix* newton_divided_differences(Matrix* x_nodes, Matrix* y_nodes) {
    return NULL;
}

float evaluate_newton_polynomial(Matrix* x_nodes, Matrix* dd, float x) {
    return 0.0f;
}

Matrix* cubic_spline(Matrix* x_nodes, Matrix* y_nodes) {
    return NULL;
}

float evaluate_cubic_spline(Matrix* x_nodes, Matrix* coeffs, float x) {
    return 0.0f;
}
