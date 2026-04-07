#include "probability.h"
#include <stdio.h>
#include <stdlib.h>

float mean(float* data, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float result = sum / size;
    return result;
}

float variance(float* data, int size) {
    float mean_value = mean(data, size);
    float sum = 0;
    for (int i=0;i < size;i++) {
        sum += pow(data[i] - mean_value, 2);
    }
    float result = sum / size;
    return result;
}

float standard_deviation(float* data, int size) {
    float result = sqrt(variance(data, size));
    return result;
}