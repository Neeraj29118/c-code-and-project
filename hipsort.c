#include <stdio.h>
#include <stdlib.h>

// Define the Heap data structure
typedef struct {
    int* array;      // Dynamic array to store heap elements
    int capacity;    // Maximum capacity of the heap
    int size;        // Current number of elements in heap
} Heap;

// Function to create a new heap
Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (!heap) return NULL;
    
    heap->array = (int*)malloc(capacity * sizeof(int));
    if (!heap->array) {
        free(heap);
        return NULL;
    }
    
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Get parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Get left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Get right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to heapify a subtree rooted at index i
void heapify(Heap* heap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Function to insert a new element into the heap
void insert(Heap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    // Insert new key at the end
    int i = heap->size;
    heap->array[i] = key;
    heap->size++;

    // Fix the max heap property if violated
    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

// Function to extract maximum element (root) from heap
int extractMax(Heap* heap) {
    if (heap->size <= 0)
        return -1;

    int maxItem = heap->array[0];

    // Replace root with last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Heapify root
    heapify(heap, 0);

    return maxItem;
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Create a heap
    Heap* heap = createHeap(n);
    
    // Insert all elements into the heap
    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }
    
    // Extract elements from heap in decreasing order
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(heap);
    }
    
    // Clean up
    free(heap->array);
    free(heap);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the implementation
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    // Demonstrate heap operations
    printf("\nDemonstrating Heap Operations:\n");
    Heap* heap = createHeap(10);
    
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 25);

    printf("Maximum element: %d\n", extractMax(heap));
    printf("Maximum element: %d\n", extractMax(heap));

    // Clean up
    free(heap->array);
    free(heap);

    return 0;
}