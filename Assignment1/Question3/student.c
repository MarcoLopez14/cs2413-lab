#include "Student.h"
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;

    int* result = (int*)malloc(sizeof(int) * digitsSize);

    for (int i = 0; i < digitsSize; i++) {
        result[i] = digits[i];
    }

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (result[i] + carry < 10) {
            result[i] += carry;
            carry = 0;
            break;
        } else {
            result[i] = 0;
            carry = 1;
        }
    }

    if (carry == 1) {
        int* newResult = (int*)malloc(sizeof(int) * (digitsSize + 1));

        newResult[0] = 1;
        for (int i = 0; i < digitsSize; i++) {
            newResult[i + 1] = 0;
        }

        *returnSize = digitsSize + 1;
        free(result);
        return newResult;
    }

    *returnSize = digitsSize;
    return result;
}