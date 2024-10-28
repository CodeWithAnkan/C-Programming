#include <stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int* A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int* A, int low, int high) {
    int pivot = A[low];
    int i = low;       // Start i at low
    int j = high + 1;  // Start j just outside the high boundary

    do {
        // Find an element on the left that should be on the right
        do {
            i++;
        } while (i <= high && A[i] <= pivot);

        // Find an element on the right that should be on the left
        do {
            j--;
        } while (A[j] > pivot);

        // Swap elements if i < j
        if (i < j) {
            swap(A, i, j);
        }
    } while (i < j);  // Continue until i and j cross

    // Place the pivot in the correct position
    swap(A, low, j);
    return j; // Return pivot index
}

void quickSort(int* A, int low, int high) {
    if (low < high) {
        int j = Partition(A, low, high);
        quickSort(A, low, j - 1);  // Sort elements to the left of pivot
        quickSort(A, j + 1, high); // Sort elements to the right of pivot
    }
}

int main() {
    int A[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = 9;

    printf("Array before sorting: ");
    printArray(A, n);

    quickSort(A, 0, n - 1); // Correctly pass n - 1 as high

    printf("Array after sorting: ");
    printArray(A, n);

    return 0;
}