#include<stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
       printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void deletion(int arr[], int size, int index){
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    
}

int main(){
    //              0  1  2   3   4
    int arr[100] = {7, 8, 12, 45, 88};
    //     Step 1: {7, 12, 12, 45, 88}
    //     Step 2: {7, 12, 45, 45, 88}
    //     Step 3: {7, 12, 45, 88, 88}
    int size = 5, index = 1;
    display(arr, size);
    deletion(arr, size, index);
    display(arr, size-1);
    return 0;
}