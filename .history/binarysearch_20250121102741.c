#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[] , int start, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

            if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;    
    }
    return -1;
}

int main() {
    int arr[] = {7, 9, 13, 17, 21, 23, 24, 27, 29, 35, 39, 47};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarysearch(arr, target, size);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}


