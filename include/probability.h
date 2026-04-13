#ifndef PROBABILITY_H
#define PROBABILITY_H

/**
 * @brief Compute the arithmetic mean of an array.
 * @param data Array of floats.
 * @param size Number of elements.
 * @return The mean value.
 */
float mean(float* data, int size);

/**
 * @brief Compute the population variance of an array.
 * @param data Array of floats.
 * @param size Number of elements.
 * @return The variance.
 */
float variance(float* data, int size);

/**
 * @brief Compute the population standard deviation of an array.
 * @param data Array of floats.
 * @param size Number of elements.
 * @return The standard deviation.
 */
float standard_deviation(float* data, int size);

/**
 * @brief Return the sign of a number: -1, 0, or 1.
 */
int sign(float n);

#endif
