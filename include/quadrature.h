#ifndef QUADRATURE_H
#define QUADRATURE_H

/**
 * @brief Integrate f over [a, b] using the composite trapezoidal rule with n subintervals.
 * @param f Integrand.
 * @param a Left endpoint.
 * @param b Right endpoint.
 * @param n Number of subintervals (n >= 1).
 * @return Approximate integral.
 */
float trapezoidal_rule(float (*f)(float), float a, float b, int n);

/**
 * @brief Integrate f over [a, b] using the composite Simpson rule with n subintervals.
 * @param f Integrand.
 * @param a Left endpoint.
 * @param b Right endpoint.
 * @param n Number of subintervals (must be even).
 * @return Approximate integral.
 */
float simpson_rule(float (*f)(float), float a, float b, int n);

/**
 * @brief Integrate f over [a, b] using n-point Gauss-Legendre quadrature.
 * @param f Integrand.
 * @param a Left endpoint.
 * @param b Right endpoint.
 * @param n Number of quadrature points (1 <= n <= 5 supported).
 * @return Approximate integral.
 */
float gaussian_quadrature(float (*f)(float), float a, float b, int n);

/**
 * @brief Integrate f over [a, b] using Romberg integration.
 * @param f Integrand.
 * @param a Left endpoint.
 * @param b Right endpoint.
 * @param max_level Maximum number of Richardson extrapolation levels.
 * @param tol Convergence tolerance.
 * @return Approximate integral.
 */
float romberg_integration(float (*f)(float), float a, float b, int max_level, float tol);

/**
 * @brief Estimate f'(x) using the central finite difference formula.
 * @param f Scalar function.
 * @param x Evaluation point.
 * @param h Step size.
 * @return Approximation of f'(x): (f(x+h) - f(x-h)) / (2h).
 */
float numerical_differentiation(float (*f)(float), float x, float h);

/**
 * @brief Improve a finite-difference estimate of f'(x) via Richardson extrapolation.
 * @param f Scalar function.
 * @param x Evaluation point.
 * @param h Initial step size.
 * @return Higher-order estimate of f'(x) using two step sizes h and h/2.
 */
float richardson_extrapolation(float (*f)(float), float x, float h);

#endif
