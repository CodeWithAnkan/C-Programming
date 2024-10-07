#include<stdio.h>

int main(){
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
    {
        printf("It is a lowercase");
    }
    else
    {
        printf("Not a lowercase");
    }

    return 0;
}