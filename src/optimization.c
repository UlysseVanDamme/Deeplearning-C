#include <stdio.h>
#include <math.h>
#include "optimization.h"
#include "linalg.h"

Matrix* steepest_descent(float (*f)(Matrix*), Matrix* (*grad_f)(Matrix*), Matrix* x0, float lr, float tol, int max_iter) {
    return NULL;
}

Matrix* newton_optimization(float (*f)(Matrix*), Matrix* (*grad_f)(Matrix*), Matrix* (*hess_f)(Matrix*), Matrix* x0, float tol, int max_iter) {
    return NULL;
}

Matrix* nelder_mead(float (*f)(Matrix*), Matrix* simplex, float tol, int max_iter) {
    return NULL;
}
