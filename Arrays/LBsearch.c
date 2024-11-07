#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key) {
            printf("%d is present at index %d\n", key, i);
            return i; // Return the index if the element is found
        }
    }
    printf("%d is not present in the array\n", key);
    return -1; // Return -1 if the element is not found
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[20] = {4, 6, 8, 10, 45, 50};
    int size = 6;

    linearSearch(arr, size, 9);
    int key = 50;
    int searchIndex = binarySearch(arr, size, key);
    printf("The element %d was found at index %d\n", key, searchIndex);
    return 0;
}