#include "machine_learning.h"


float calculate_loss(Matrix* predicted, Matrix* actual, float (*function_ptr)(float, float)) {
    if (predicted->rows != actual->rows || predicted->cols != actual->cols) {
        printf("Predicted and actual matrices must have the same dimensions");
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < predicted->rows; i++) {
        for (int j = 0; j < predicted->cols; j++) {
            sum += function_ptr(get_value(predicted, i, j), get_value(actual, i, j));
        }
    }
    return sum / (predicted->rows * predicted->cols);
}

// loss functions

float mean_squared_error(float predicted, float actual) {
    float result = pow(predicted - actual, 2);
    return result;
}

float mean_absolute_error(float predicted, float actual) {
    float result = abs(predicted - actual);
    return result;
}

Matrix* lineair_least_squares(Matrix* A, Matrix* y) {
    QR_result qr = QR_decomposition(A);
    int n = qr.R->cols;
    print_matrix(matrix_multiply(qr.Q, qr.R));

    Matrix* trimmed_R = make_empty_matrix(n, n);
    for (int i = 0; i < n; i++) {
        set_row(trimmed_R, get_row(qr.R, i), i);
    }
    Matrix* transposed = transpose(qr.Q);
    Matrix* multiplied = matrix_multiply(transposed, y);
    Matrix* b = make_empty_matrix(n, 1);
    for (int i = 0; i < n; i++) {
        set_value(b, i, 0, get_value(multiplied, i, 0));
    }
    Matrix* result = backward_substitution(trimmed_R, b);

    free_matrix(qr.Q);
    free_matrix(qr.R);
    free_matrix(transposed);
    free_matrix(multiplied);
    free_matrix(trimmed_R);
    free_matrix(b);

    return result;
}
