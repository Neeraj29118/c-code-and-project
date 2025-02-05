#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

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
