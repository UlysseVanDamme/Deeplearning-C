#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include "matrix.h"

/**
 * @brief Compute coefficients of the interpolating polynomial in the monomial basis.
 * @param x_nodes Column vector of n distinct interpolation nodes.
 * @param y_nodes Column vector of n function values at x_nodes.
 * @return Coefficient vector (n x 1): c[0] + c[1]*x + ... + c[n-1]*x^{n-1}.
 */
Matrix* monomial_interpolation(Matrix* x_nodes, Matrix* y_nodes);

/**
 * @brief Evaluate the Lagrange interpolating polynomial at x.
 * @param x_nodes Column vector of n distinct interpolation nodes.
 * @param y_nodes Column vector of n function values at x_nodes.
 * @param x Evaluation point.
 * @return Interpolated value p(x).
 */
float lagrange_interpolation(Matrix* x_nodes, Matrix* y_nodes, float x);

/**
 * @brief Compute the Newton divided differences table.
 * @param x_nodes Column vector of n distinct interpolation nodes.
 * @param y_nodes Column vector of n function values at x_nodes.
 * @return Column vector (n x 1) of divided difference coefficients f[x0], f[x0,x1], ...
 */
Matrix* newton_divided_differences(Matrix* x_nodes, Matrix* y_nodes);

/**
 * @brief Evaluate the Newton interpolating polynomial at x.
 * @param x_nodes Column vector of interpolation nodes.
 * @param dd Divided differences from newton_divided_differences().
 * @param x Evaluation point.
 * @return Interpolated value p(x).
 */
float evaluate_newton_polynomial(Matrix* x_nodes, Matrix* dd, float x);

/**
 * @brief Compute natural cubic spline coefficients for n nodes.
 * @param x_nodes Column vector of n strictly increasing nodes.
 * @param y_nodes Column vector of n function values at x_nodes.
 * @return Matrix of size (n-1) x 4; row i contains [a_i, b_i, c_i, d_i]
 *         for the piece a_i + b_i*(x-x_i) + c_i*(x-x_i)^2 + d_i*(x-x_i)^3.
 */
Matrix* cubic_spline(Matrix* x_nodes, Matrix* y_nodes);

/**
 * @brief Evaluate a cubic spline at x.
 * @param x_nodes Column vector of n nodes used when building the spline.
 * @param coeffs Coefficient matrix from cubic_spline() (size (n-1) x 4).
 * @param x Evaluation point.
 * @return Interpolated value s(x).
 */
float evaluate_cubic_spline(Matrix* x_nodes, Matrix* coeffs, float x);

#endif
