#include <stdio.h>

void findMinMax(int a[], int i, int j, int *min, int *max) {
    int mid;

    if (i == j) {  // Only one element
        *min = *max = a[i];
    } else if (j == i + 1) {  // Two elements
        if (a[i] < a[j]) {
            *min = a[i];
            *max = a[j];
        } else {
            *min = a[j];
            *max = a[i];
        }
    } else {  // More than two elements
        mid = (i + j) / 2;
        int min1, max1, min2, max2;

        findMinMax(a, i, mid, &min1, &max1);  // Find min and max for the left half
        findMinMax(a, mid + 1, j, &min2, &max2);  // Find min and max for the right half

        if (min1 < min2) {
            *min = min1;
        } else {
            *min = min2;
        }

        if (max1 > max2) {
            *max = max1;
        } else {
            *max = max2;
        }
    }
}

int main() {
    int a[] = {5, 12, 11, 4, 6, 7, 9, 8, 14, 10};
    int size = sizeof(a) / sizeof(a[0]);

    int min, max;
    findMinMax(a, 0, size - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}

