#include<stdio.h>
int main(){
    int length, width, area;
    printf("Enter the length and width of the rectangle: ");
    scanf("%d %d", &length, &width);
    area = length * width;
    printf("The area is: %d unit^2", area);

    return 0;
}