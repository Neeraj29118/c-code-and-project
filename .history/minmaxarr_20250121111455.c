#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void findMinMax(int arr[], int i, int j, int *min, int *max) {
    int mid;

    if (i == j) {  // Only one element
        *min = *max = arr[i];
    } else if (j == i + 1) {  // Two elements
        if (arr[i] < arr[j]) {
            *min = arr[i];
            *max = arr[j];
        } else {
            *min = arr[j];
            *max = arr[i];
        }
    } else {  // More than two elements
        mid = (i + j) / 2;
        int minLeft, maxLeft, minRight, maxRight;

        findMinMax(arr, i, mid, &minLeft, &maxLeft);
        findMinMax(arr, mid + 1, j, &minRight, &maxRight);

        *min = MIN(minLeft, minRight);
        *max = MAX(maxLeft, maxRight);
    }
}

int main() {
    int arr[] = {5, 12, 11, 4, 6, 7, 9, 8, 14, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int min, max;
    findMinMax(arr, 0, size - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
