#include<stdio.h>

int main(){
    int i = 2;
    int *ptr = &i;
    printf("The address of i is: %u\n", &i);
    printf("The value of i is: %d", *ptr);

    return 0;
}