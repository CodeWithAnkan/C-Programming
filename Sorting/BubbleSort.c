#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    { // For number of pass
        printf("Working on pass number %d\n", i);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        { // For comparison in each pass
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int b[] = {7, 9, 12, 23, 54, 65};
    int n = 6;
    printArray(a, n);
    bubbleSort(a, n);
    printArray(a, n);

    return 0;
}