#include <stdio.h>

// Recursive function to check if a number exists in the array
int isInSet(int arr[], int index, int size, int target) {
    if (index >= size) { 
        // Base case: if we reach the end of the array, return 0 (not found)
        return 0;
    }
    if (arr[index] == target) { 
        // If the current element matches the target, return 1 (found)
        return 1;
    }
    // Recursive case: check the next element
    return isInSet(arr, index + 1, size, target);
}

int main() {
    int set[] = {7, 9, 13, 17, 21, 23, 24, 27, 29, 35, 39, 47};
    int size = sizeof(set) / sizeof(set[0]);

    int target;
    printf("Enter a number to check: ");
    scanf("%d", &target);

    if (isInSet(set, 0, size, target)) {
        printf("%d is in the set.\n", target);
    } else {
        printf("%d is not in the set.\n", target);
    }

    return 0;
}
