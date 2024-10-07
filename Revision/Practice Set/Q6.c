#include<stdio.h>

int main(){
    float income;
    printf("Enter your income: ");
    scanf("%f", &income);
    float after_tax, after_tax1, after_tax2;

    after_tax = income * 0.05;
    after_tax1 = income * 0.20;
    after_tax2 = income * 0.30;


    if (income < 250000)
    {
        printf("No Tax is to be paid");
    } else if (income > 250000 && income < 500000)
    {
        printf ("You have to pay 5 percent tax i.e is : %.4f rupees", after_tax);
    }
    else if (income > 500000 && income < 1000000)
    {
        printf ("You have to pay 20 percent tax i.e is : %.4f rupees", after_tax1);
    }
    else
    {
        printf ("You have to pay 30 percent tax i.e is : %.4f rupees", after_tax2);
    }
    
    
    return 0;
}