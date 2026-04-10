#ifndef MACHINE_LEARNING_H
#define MACHINE_LEARNING_H
#include "matrix.h"

float calculate_loss(Matrix* predicted, Matrix* actual, float (*function_ptr)(float, float));

// loss functions
float mean_squared_error(float predicted, float actual);
float mean_absolute_error(float predicted, float actual);

#endif