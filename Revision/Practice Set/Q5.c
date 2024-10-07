#include<stdio.h>

int main (){
    float afl, dsd, ds;
    printf("Enter the marks of AFL: ");
    scanf("%f", &afl);
    printf("Enter the marks of DSD: ");
    scanf("%f", &dsd);
    printf("Enter the marks of DS: ");
    scanf("%f", &ds);

    int total_marks = (afl + dsd + ds);
    float total_marks_percent = (afl + dsd + ds)/300;
    if ( total_marks_percent < 0.4 || afl < 33 || dsd < 33 || ds < 33)
    {
        printf("Your score is %d out of 300\n", total_marks);
        printf("Better luck next time");
    } else {
        printf("Your score is %d out of 300\n", total_marks);
        printf("You passed");
    }

    return 0;
}