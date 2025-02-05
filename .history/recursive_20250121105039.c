#include <stdio.h>

// Recursive function to check if a number exists in the array
int isInSet(int arr[], int index, int size, int target) {
    // Base case: If the index reaches the size of the array, stop recursion
    if (index == size) {
        return 0; // Not found
    }

    // Check if the current element matches the target
    if (arr[index] == target) {
        return 1; // Found
    }

    // Recursive case: Check the next element
    return isInSet(arr, index + 1, size, target);
}

int main() {
    int set[] = {7, 9, 13, 17, 21, 23, 24, 27, 29, 35, 39, 47};
    int size = sizeof(set) / sizeof(set[0]);

    int target;
    printf("Enter a number to check: ");
    scanf("%d", &target);

    // Start the recursion from index 0
    if (isInSet(set, 0, size, target)) {
        printf("%d is in the set.\n", target);
    } else {
        printf("%d is not in the set.\n", target);
    }

    return 0;
}
