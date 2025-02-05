#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n, const char* message) {
    printf("%s: ", message);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 1. Bubble Sort - O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// 2. Selection Sort - O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// 3. Insertion Sort - O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 4. Merge Sort - O(n log n)
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort - O(n log n)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort - O(n log n)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Counting Sort - O(n + k)
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
            
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
        
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
        
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
        
    free(count);
    free(output);
}

// 8. Radix Sort - O(d * (n + k))
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSortForRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};
    
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
        
    free(output);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

// Main function to demonstrate all sorting algorithms
int main() {
    int test_arrays[][10] = {
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4},
        {64, 34, 25, 12, 22, 11, 90, 8, 1, 4}
    };
    int n = 10;

    printf("\n=== Demonstration of Different Sorting Algorithms ===\n\n");

    // 1. Bubble Sort
    printf("Bubble Sort:\n");
    printArray(test_arrays[0], n, "Original");
    bubbleSort(test_arrays[0], n);
    printArray(test_arrays[0], n, "Sorted");
    printf("\n");

    // 2. Selection Sort
    printf("Selection Sort:\n");
    printArray(test_arrays[1], n, "Original");
    selectionSort(test_arrays[1], n);
    printArray(test_arrays[1], n, "Sorted");
    printf("\n");

    // 3. Insertion Sort
    printf("Insertion Sort:\n");
    printArray(test_arrays[2], n, "Original");
    insertionSort(test_arrays[2], n);
    printArray(test_arrays[2], n, "Sorted");
    printf("\n");

    // 4. Merge Sort
    printf("Merge Sort:\n");
    printArray(test_arrays[3], n, "Original");
    mergeSort(test_arrays[3], 0, n - 1);
    printArray(test_arrays[3], n, "Sorted");
    printf("\n");

    // 5. Quick Sort
    printf("Quick Sort:\n");
    printArray(test_arrays[4], n, "Original");
    quickSort(test_arrays[4], 0, n - 1);
    printArray(test_arrays[4], n, "Sorted");
    printf("\n");

    // 6. Heap Sort
    printf("Heap Sort:\n");
    printArray(test_arrays[5], n, "Original");
    heapSort(test_arrays[5], n);
    printArray(test_arrays[5], n, "Sorted");
    printf("\n");

    // 7. Counting Sort
    printf("Counting Sort:\n");
    printArray(test_arrays[6], n, "Original");
    countingSort(test_arrays[6], n);
    printArray(test_arrays[6], n, "Sorted");
    printf("\n");

    // 8. Radix Sort
    printf("Radix Sort:\n");
    printArray(test_arrays[7], n, "Original");
    radixSort(test_arrays[7], n);
    printArray(test_arrays[7], n, "Sorted");
    printf("\n");

    return 0;
}