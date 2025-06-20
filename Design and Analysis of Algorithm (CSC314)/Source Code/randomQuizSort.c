#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Lomuto style)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot is at end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized partition function
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Random pivot
    swap(&arr[randomIndex], &arr[high]); // Swap with end
    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {23, 45, 12, 8, 19, 56, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Seed random number generator
    srand(time(0));

    printf("Original array:\n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted array using Randomized Quick Sort:\n");
    printArray(arr, n);

    return 0;
}
