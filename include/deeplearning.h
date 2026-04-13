#ifndef DEEPLEARNING_H
#define DEEPLEARNING_H
#include "matrix.h"

/* Activation functions */

/**
 * @brief ReLU activation: returns max(0, x).
 * @param x Input value.
 * @return x if x > 0, otherwise 0.
 */
float relu(float x);

#endif
