#include<stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
       printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int insertion(int arr[], int n, int key, int capacity, int index){
    if(n >= capacity){
        return -1;
    }
    for (int i = n - 1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = key;
    return 1;
}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int n = 5, element = 45, index = 3;
    display(arr, n);
    insertion(arr, n, element, 100, index);
    display(arr, n+1);

    return 0;
}