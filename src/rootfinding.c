#include <stdio.h>
#include <math.h>
#include "rootfinding.h"
#include "linalg.h"

float bisection(float (*f)(float), float a, float b, float tol, int max_iter) {
    return 0.0f;
}

float fixed_point_iteration(float (*g)(float), float x0, float tol, int max_iter) {
    return 0.0f;
}

float newton_raphson(float (*f)(float), float (*df)(float), float x0, float tol, int max_iter) {
    return 0.0f;
}

float secant_method(float (*f)(float), float x0, float x1, float tol, int max_iter) {
    return 0.0f;
}

Matrix* newton_raphson_system(Matrix* (*F)(Matrix*), Matrix* (*J)(Matrix*), Matrix* x0, float tol, int max_iter) {
    return NULL;
}
