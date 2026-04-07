#ifndef MACHINE_LEARNING_H
#define MACHINE_LEARNING_H
#include "matrix.h"

float calculate_loss(Matrix* predicted, Matrix* actual, float (*function_ptr)(float, float));

#endif