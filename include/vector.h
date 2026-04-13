#ifndef VECTOR_H
#define VECTOR_H
#include "matrix.h"

/**
 * @brief Check if a matrix is a vector (single row or single column).
 * @return 1 if vector, 0 otherwise.
 */
int is_vector(Matrix* vector);

/**
 * @brief Compute the dot product of two vectors.
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return Scalar dot product, or 0 if inputs are not vectors.
 */
float dot_product(Matrix* v1, Matrix* v2);

/**
 * @brief Compute the p-norm of a column vector: (sum |x_i|^p)^(1/p).
 * @param vector Column vector.
 * @param p Norm order (e.g. 2 for Euclidean norm).
 * @return The p-norm value.
 */
float p_norm(Matrix* vector, int p);

/**
 * @brief Compute the infinity/max norm of a vector: max(|x_i|).
 * @return The max norm value, or 0 if input is not a vector.
 */
float max_norm(Matrix* vector);

/**
 * @brief Extract a single row from a matrix as a 1 x cols row vector.
 * @param matrix Source matrix.
 * @param row Row index (0-based).
 * @return New row vector, or NULL on out-of-bounds.
 */
Matrix* get_row(Matrix* matrix, int row);

/**
 * @brief Extract a single column from a matrix as a rows x 1 column vector.
 * @param matrix Source matrix.
 * @param col Column index (0-based).
 * @return New column vector, or NULL on out-of-bounds.
 */
Matrix* get_col(Matrix* matrix, int col);

/**
 * @brief Replace a row in a matrix with the given row vector.
 * @param matrix Target matrix (modified in-place).
 * @param r Row vector to copy in.
 * @param row Row index (0-based).
 */
void set_row(Matrix* matrix, Matrix* r, int row);

/**
 * @brief Replace a column in a matrix with the given column vector.
 * @param matrix Target matrix (modified in-place).
 * @param c Column vector to copy in.
 * @param col Column index (0-based).
 */
void set_col(Matrix* matrix, Matrix* c, int col);


#endif
