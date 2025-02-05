#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int i, int j) {
    MinMax result, left, right;

    if (i == j) { // Only one element
        result.min = result.max = arr[i];
        return result;
    }

    if (j == i + 1) { // Two elements
        if (arr[i] < arr[j]) {
            result.min = arr[i];
            result.max = arr[j];
        } else {
            result.min = arr[j];
            result.max = arr[i];
        }
        return result;
    }

    int mid = (i + j) / 2;
    left = findMinMax(arr, i, mid);
    right = findMinMax(arr, mid + 1, j);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {5, 12, 11, 4, 6, 7, 9, 8, 14, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, size - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}
