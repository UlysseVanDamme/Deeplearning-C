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
