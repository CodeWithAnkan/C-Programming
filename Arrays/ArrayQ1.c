#include<stdio.h>

void array (int* A, int size){
    int i;
    for (int i = 0; i < size; i++)
    {
        printf("Element address: %p, Element: %d", &A[i], A[i]);
        printf("\n");
    }   
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    array(A, 5);

    return 0;
}