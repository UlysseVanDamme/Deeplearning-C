#ifndef MATRIX_H
#define MATRIX_H

/** @brief Matrix */
typedef struct {
    int rows;
    int cols;
    float* data;
} Matrix;

/**
 * @brief Allocate a matrix with uninitialized data.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Pointer to the new matrix, or NULL on allocation failure.
 */
Matrix* make_matrix(int rows, int cols);

/**
 * @brief Allocate a matrix with all elements initialized to zero.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Pointer to the new matrix, or NULL on allocation failure.
 */
Matrix* make_empty_matrix(int rows, int cols);

/**
 * @brief Get the value at (row, col).
 * @param m Source matrix.
 * @param row Row index (0-based).
 * @param col Column index (0-based).
 * @return The element value, or 0 on out-of-bounds/NULL.
 */
float get_value(Matrix* m, int row, int col);

/**
 * @brief Set the value at (row, col).
 * @param m Target matrix.
 * @param row Row index (0-based).
 * @param col Column index (0-based).
 * @param number Value to set.
 */
void set_value(Matrix* m, int row, int col, float number);

/**
 * @brief Free a matrix and its data.
 * @param m Matrix to free. Safe to call with NULL.
 */
void free_matrix(Matrix* m);

/** @brief Print a matrix to stdout in a readable format. */
void print_matrix(Matrix* m);

/** @brief Compute the max column-sum norm (1-norm): max_j sum_i |a_ij|. */
float matrix_norm_1(Matrix* a);

/** @brief Compute the max row-sum norm (infinity-norm): max_i sum_j |a_ij|. */
float matrix_norm_inf(Matrix* a);

/** @brief Compute the Frobenius norm: sqrt(sum of squared elements). */
float frobenius_norm(Matrix* a);

/**
 * @brief Element-wise matrix multiplication C = A * B.
 * @param a Left matrix (m x n).
 * @param b Right matrix (n x p).
 * @return New matrix (m x p), or NULL if dimensions are incompatible.
 */
Matrix* matrix_multiply(Matrix* a, Matrix* b);

/**
 * @brief Element-wise addition C = A + B.
 * @return New matrix, or NULL if dimensions don't match.
 */
Matrix* matrix_add(Matrix* a, Matrix* b);

/**
 * @brief Element-wise subtraction C = A - B.
 * @return New matrix, or NULL if dimensions don't match.
 */
Matrix* matrix_sub(Matrix* a, Matrix* b);

/**
 * @brief Scale every element of a in-place by scalar b.
 * @param a Matrix to scale (modified in-place).
 * @param b Scalar factor.
 */
void matrix_scale(Matrix* a, float b);

/** @brief Check if a matrix is square.
 *  @return 1 if square, 0 otherwise. */
int is_square(Matrix* a);

/** @brief Compute the trace (sum of diagonal elements). Requires a square matrix. */
float trace(Matrix* a);

/**
 * @brief Compute the transpose of a.
 * @return New matrix that is the transpose.
 */
Matrix* transpose(Matrix* a);

/**
 * @brief Create an identity matrix of the given size.
 * @param size Number of rows/columns.
 * @return New size x size identity matrix.
 */
Matrix* identity_matrix(int size);

/**
 * @brief Create a deep copy of a matrix.
 * @return New matrix with the same dimensions and values.
 */
Matrix* copy_new_matrix(Matrix* m);

/**
 * @brief Copy all elements from m1 into m2. Assumes m2 has the same dimensions.
 * @param m1 Source matrix.
 * @param m2 Destination matrix (modified in-place).
 */
void copy_matrix(Matrix* m1, Matrix* m2);


#endif
