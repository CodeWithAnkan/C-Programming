#include<stdio.h>

int main(){
    int i = 6;
    int* j = &i;
    int** k = &j;
    int*** l = &k;

    printf("%d\n", *j);
    printf("%d\n", **k);
    printf("%d\n", ***l);
}