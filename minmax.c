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
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}
