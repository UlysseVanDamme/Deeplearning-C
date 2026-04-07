#include "deeplearning.h"
#include <math.h>
#include <stdio.h>

float relu(float x) {
    if (x < 0) {
        return 0;
    } else {
        return x;
    }
}