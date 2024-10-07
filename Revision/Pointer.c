#include<stdio.h>

int main(){
    int i, *j;
    j = &i;
    *j = 10;
    printf("%p\n", i);
    printf("%p\n", *j);
    printf("%p\n", &j);
    printf("%p\n", &i);
    printf("%p\n", j);
    return 0;
}