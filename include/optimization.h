#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H
#include "matrix.h"

/**
 * @brief Minimize f using steepest descent (gradient descent) with fixed step size.
 * @param f Objective function; takes x (n x 1), returns scalar.
 * @param grad_f Gradient of f; takes x (n x 1), returns gradient (n x 1).
 * @param x0 Initial point (n x 1).
 * @param lr Learning rate (step size).
 * @param tol Convergence tolerance on ||grad_f(x)||.
 * @param max_iter Maximum number of iterations.
 * @return Approximate minimizer (n x 1), or NULL on failure.
 */
Matrix* steepest_descent(float (*f)(Matrix*), Matrix* (*grad_f)(Matrix*), Matrix* x0, float lr, float tol, int max_iter);

/**
 * @brief Minimize f using Newton's method: x_{k+1} = x_k - H(x_k)^{-1} grad_f(x_k).
 * @param f Objective function; takes x (n x 1), returns scalar.
 * @param grad_f Gradient of f; takes x (n x 1), returns gradient (n x 1).
 * @param hess_f Hessian of f; takes x (n x 1), returns Hessian (n x n).
 * @param x0 Initial point (n x 1).
 * @param tol Convergence tolerance on ||grad_f(x)||.
 * @param max_iter Maximum number of iterations.
 * @return Approximate minimizer (n x 1), or NULL on failure.
 */
Matrix* newton_optimization(float (*f)(Matrix*), Matrix* (*grad_f)(Matrix*), Matrix* (*hess_f)(Matrix*), Matrix* x0, float tol, int max_iter);

/**
 * @brief Minimize f using the Nelder-Mead simplex method (derivative-free).
 * @param f Objective function; takes x (n x 1), returns scalar.
 * @param simplex Initial simplex as (n+1) x n matrix; each row is one vertex.
 * @param tol Convergence tolerance on simplex diameter.
 * @param max_iter Maximum number of iterations.
 * @return Approximate minimizer (n x 1), or NULL on failure.
 */
Matrix* nelder_mead(float (*f)(Matrix*), Matrix* simplex, float tol, int max_iter);

#endif
