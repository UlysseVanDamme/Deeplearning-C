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

/** @brief Result of a pivoted LU decomposition: PA = L * U. */
typedef struct {
    Matrix* P; /**< Permutation matrix. */
    Matrix* L; /**< Lower triangular matrix. */
    Matrix* U; /**< Upper triangular matrix. */
} PLU_result;

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

/**
 * @brief Compute the LU decomposition with partial pivoting: PA = L * U.
 * @param A Square matrix to decompose.
 * @return PLU_result containing P, L, U such that PA = LU.
 */
PLU_result LU_decomposition_pivoted(Matrix* A);

/**
 * @brief Estimate the condition number cond(A) = ||A|| * ||A^-1|| using the 1-norm.
 * @param a Square matrix.
 * @return Condition number estimate.
 */
float condition_number(Matrix* a);

/**
 * @brief Solve Ax = b iteratively using the Jacobi method.
 * @param A Coefficient matrix (must be diagonally dominant for convergence).
 * @param b Right-hand side vector.
 * @param tol Convergence tolerance on ||x_{k+1} - x_k||.
 * @param max_iter Maximum number of iterations.
 * @return Solution vector x, or NULL on failure to converge.
 */
Matrix* jacobi_solver(Matrix* A, Matrix* b, float tol, int max_iter);

/**
 * @brief Solve Ax = b iteratively using the Gauss-Seidel method.
 * @param A Coefficient matrix (must be diagonally dominant or SPD for convergence).
 * @param b Right-hand side vector.
 * @param tol Convergence tolerance on ||x_{k+1} - x_k||.
 * @param max_iter Maximum number of iterations.
 * @return Solution vector x, or NULL on failure to converge.
 */
Matrix* gauss_seidel_solver(Matrix* A, Matrix* b, float tol, int max_iter);

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

/**
 * @brief Find the eigenvalue of A nearest to shift using inverse power iteration.
 * @param a Square matrix.
 * @param shift Spectral shift mu; algorithm converges to eigenvalue closest to mu.
 * @param iterations Maximum number of iterations.
 * @return Eigenvalue of A nearest to shift.
 */
float inverse_power_iteration(Matrix* a, float shift, int iterations);

/**
 * @brief Compute all eigenvalues of A using the QR algorithm.
 * @param a Square matrix (eigenvalues must be real).
 * @param iterations Number of QR iterations to perform.
 * @return Column vector (n x 1) of eigenvalue approximations.
 */
Matrix* qr_algorithm(Matrix* a, int iterations);

/**
 * @brief Remove eigenvalue lambda_1 from A via Hotelling deflation: A1 = A - lambda * v * v^T.
 * @param a Square symmetric matrix.
 * @param eigenvalue The eigenvalue to deflate out.
 * @param eigenvector Corresponding unit eigenvector (n x 1).
 * @return New deflated matrix with eigenvalue replaced by 0.
 */
Matrix* deflation(Matrix* a, float eigenvalue, Matrix* eigenvector);

#endif
