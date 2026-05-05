#ifndef ROOTFINDING_H
#define ROOTFINDING_H
#include "matrix.h"

/**
 * @brief Find a root of f in [a, b] by bisection.
 * @param f Continuous scalar function.
 * @param a Left endpoint (f(a) and f(b) must have opposite signs).
 * @param b Right endpoint.
 * @param tol Convergence tolerance on interval width.
 * @param max_iter Maximum number of bisection steps.
 * @return Approximate root.
 */
float bisection(float (*f)(float), float a, float b, float tol, int max_iter);

/**
 * @brief Find a fixed point of g: x* = g(x*) by iteration x_{k+1} = g(x_k).
 * @param g Contraction mapping.
 * @param x0 Initial guess.
 * @param tol Convergence tolerance on |x_{k+1} - x_k|.
 * @param max_iter Maximum number of iterations.
 * @return Approximate fixed point.
 */
float fixed_point_iteration(float (*g)(float), float x0, float tol, int max_iter);

/**
 * @brief Find a root of f using the Newton-Raphson method.
 * @param f Scalar function.
 * @param df Derivative of f.
 * @param x0 Initial guess.
 * @param tol Convergence tolerance on |f(x)|.
 * @param max_iter Maximum number of iterations.
 * @return Approximate root.
 */
float newton_raphson(float (*f)(float), float (*df)(float), float x0, float tol, int max_iter);

/**
 * @brief Find a root of f using the secant method (derivative-free Newton).
 * @param f Scalar function.
 * @param x0 First initial point.
 * @param x1 Second initial point.
 * @param tol Convergence tolerance on |f(x)|.
 * @param max_iter Maximum number of iterations.
 * @return Approximate root.
 */
float secant_method(float (*f)(float), float x0, float x1, float tol, int max_iter);

/**
 * @brief Find a root of F: R^n -> R^n using Newton-Raphson for systems.
 * @param F Vector-valued function; takes x (n x 1), returns F(x) (n x 1).
 * @param J Jacobian of F; takes x (n x 1), returns J(x) (n x n).
 * @param x0 Initial guess (n x 1).
 * @param tol Convergence tolerance on ||F(x)||.
 * @param max_iter Maximum number of iterations.
 * @return Approximate root vector (n x 1), or NULL on failure.
 */
Matrix* newton_raphson_system(Matrix* (*F)(Matrix*), Matrix* (*J)(Matrix*), Matrix* x0, float tol, int max_iter);

#endif
