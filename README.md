# Deeplearning-C

This project meant to strengthen my understanding of the mathematical foundations behind machine learning and deep learning by implementing them from scratch in C.

I aim to rely only on two primary resources:
- *Deep Learning* (Goodfellow et al.)  
- *Mathematics for Machine Learning* (Deisenroth et al.)

---

## Implementation checklist

Order follows the Wetenschappelijk Rekenen course (C001521A, UGent).

### Linear systems

- [x] `LU_decomposition` — Gaussian elimination, A = LU
- [x] `forward_substitution` — solve Lx = b
- [x] `backward_substitution` — solve Ux = b
- [x] `lineair_solver` — full solve via LU
- [x] `cholesky_factorization` — A = LL^T for SPD matrices
- [x] `QR_decomposition` — Householder reflections
- [ ] `LU_decomposition_pivoted` — PA = LU with partial pivoting
- [ ] `condition_number` — cond(A) = ||A|| * ||A^-1||, 1-norm
- [ ] `jacobi_solver` — iterative, diagonal splitting
- [ ] `gauss_seidel_solver` — iterative, sequential update

### Least squares

- [x] `lineair_least_squares` — min||Ax - y||_2 via QR

### Eigenvalues and eigenvectors

- [x] `power_iteration` — dominant eigenvalue
- [x] `rayleigh_quotient_iteration` — cubic convergence
- [ ] `inverse_power_iteration` — eigenvalue nearest to shift
- [ ] `deflation` — Hotelling deflation, A1 = A - lambda * v * v^T
- [ ] `qr_algorithm` — all eigenvalues via repeated QR

### Root finding

- [ ] `bisection` — bracketing, guaranteed convergence
- [ ] `fixed_point_iteration` — x = g(x)
- [ ] `newton_raphson` — quadratic convergence, needs f'
- [ ] `secant_method` — superlinear, derivative-free
- [ ] `newton_raphson_system` — F: R^n -> R^n, needs Jacobian

### Optimization

- [ ] `steepest_descent` — gradient descent, fixed step size
- [ ] `newton_optimization` — x -= H^-1 * grad, quadratic convergence
- [ ] `nelder_mead` — simplex method, derivative-free

### Interpolation

- [ ] `monomial_interpolation` — Vandermonde system for coefficients
- [ ] `lagrange_interpolation` — barycentric evaluation at x
- [ ] `newton_divided_differences` — divided difference table
- [ ] `evaluate_newton_polynomial` — Horner evaluation
- [ ] `cubic_spline` — natural cubic spline coefficients
- [ ] `evaluate_cubic_spline` — piecewise evaluation

### Numerical differentiation and integration

- [ ] `numerical_differentiation` — central difference (f(x+h) - f(x-h)) / 2h
- [ ] `richardson_extrapolation` — higher-order derivative estimate
- [ ] `trapezoidal_rule` — composite trapezoidal
- [ ] `simpson_rule` — composite Simpson, n must be even
- [ ] `gaussian_quadrature` — Gauss-Legendre, 1 to 5 points
- [ ] `romberg_integration` — Richardson extrapolation on trapezoidal estimates
