#include <stdio.h>

// Merging in one array from two arrays

void merge(int A[], int B[], int C[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < n)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}

// merging in a single array

void singleMerge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++; k++;
        }
        else
        {
            B[k] = A[j];
            j++; k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++; k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++; k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void MS(int A[], int low, int high){
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MS(A, low, mid);
        MS(A, mid + 1, high);
        singleMerge (A, mid, low, high);
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6};
    int n = 7;

    printf("Array before sorting: ");
    printArray(A, n);

    MS(A, 0, 6);

    printf("Array after sorting: ");
    printArray(A, n);

    return 0;
    return 0;
}