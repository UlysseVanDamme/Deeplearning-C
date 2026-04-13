#ifndef MACHINE_LEARNING_H
#define MACHINE_LEARNING_H
#include "matrix.h"
#include "linalg.h"

/**
 * @brief Compute the average loss between predicted and actual values.
 * @param predicted Matrix of predicted values.
 * @param actual Matrix of actual/target values (must have same dimensions).
 * @param function_ptr Per-element loss function taking (predicted, actual).
 * @return Average loss across all elements, or 0 if dimensions don't match.
 */
float calculate_loss(Matrix* predicted, Matrix* actual, float (*function_ptr)(float, float));

/**
 * @brief Squared error for a single pair: (predicted - actual)^2.
 * @note Use as a function_ptr argument to calculate_loss().
 */
float mean_squared_error(float predicted, float actual);

/**
 * @brief Absolute error for a single pair: |predicted - actual|.
 * @note Use as a function_ptr argument to calculate_loss().
 */
float mean_absolute_error(float predicted, float actual);

/**
 * @brief Solve the linear least squares problem min||Ax - y||_2 using QR factorization.
 * @param x Design matrix A (m x n, m >= n).
 * @param y Observation vector (m x 1).
 * @return Coefficient vector (n x 1) that minimizes the residual.
 */
Matrix* lineair_least_squares(Matrix* x, Matrix* y);

#endif
