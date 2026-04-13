#ifndef LINALG_H
#define LINALG_H
#include "vector.h"

/** @brief Result of a QR decomposition: A = Q * R. */
typedef struct {
    Matrix* Q; /**< Orthogonal matrix. */
    Matrix* R; /**< Upper triangular matrix. */
} QR_result;

/** @brief Result of an LU decomposition: A = L * U. */
typedef struct {
    Matrix* L; /**< Lower triangular matrix. */
    Matrix* U; /**< Upper triangular matrix. */
} LU_result;

/**
 * @brief Compute the LU decomposition of a square matrix.
 * @param A Square matrix to decompose.
 * @return LU_result containing L and U such that A = L * U.
 */
LU_result LU_decomposition(Matrix* A);

/**
 * @brief Solve the linear system Ax = b using LU decomposition.
 * @param a Coefficient matrix A.
 * @param b Right-hand side vector.
 * @return Solution vector x, or NULL if the system is singular.
 */
Matrix* lineair_solver(Matrix*a, Matrix* b);

/**
 * @brief Compute the Cholesky factorization A = L * L^T.
 * @param A Symmetric positive-definite matrix.
 * @return Lower triangular matrix L.
 */
Matrix* cholesky_factorization(Matrix* A);

/**
 * @brief Compute the QR decomposition using Householder transformations.
 * @param a Matrix to decompose (m x n, m >= n).
 * @return QR_result containing orthogonal Q and upper triangular R.
 */
QR_result QR_decomposition(Matrix* a);

/**
 * @brief Solve an upper triangular system Ux = B by back-substitution.
 * @param U Upper triangular matrix.
 * @param B Right-hand side column vector.
 * @return Solution vector x, or NULL if a diagonal element is zero.
 */
Matrix* backward_substitution(Matrix* U, Matrix* B);

/**
 * @brief Solve a lower triangular system Lx = B by forward substitution.
 * @param L Lower triangular matrix.
 * @param B Right-hand side column vector.
 * @return Solution vector x, or NULL if a diagonal element is zero.
 */
Matrix* forward_substitution(Matrix* L, Matrix* B);

/* Eigenvalues and Eigenvectors */

/**
 * @brief Estimate the dominant eigenvalue using the power iteration method.
 * @param a Square matrix.
 * @param iterations Number of iterations to perform.
 * @return Approximation of the largest eigenvalue
 */
float power_iteration(Matrix* a, int iterations);

/**
 * @brief Estimate an eigenvalue using Rayleigh quotient iteration.
 *
 * Converges cubically to the eigenvalue closest to the initial Rayleigh quotient.
 * Uses LU-based linear solves internally.
 *
 * @param a Square matrix.
 * @param iterations Maximum number of iterations.
 * @return Approximated eigenvalue.
 */
float rayleigh_quotient_iteration(Matrix* a, int iterations);

#endif
