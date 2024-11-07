#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->totalSize = tSize;
    a->usedSize = uSize;
    a->ptr = (int *)malloc(a->totalSize * sizeof(int));
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\t", a->ptr[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 50, 10);
    setVal(&marks);
    show(&marks);
    return 0;
}