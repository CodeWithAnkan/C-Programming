#include<stdio.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 97 == 0)
    {
        printf("Number is divisible by 97");
    } else {
        printf("Number is not divisible by 97");
    }
    

    return 0;
}