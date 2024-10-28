#include <stdio.h>
#include <stdlib.h>
int stack[100];
int n, top = -1;

void push(int item)
{
    if (top >= n - 1)
        printf("Stack overflow. Element not pushed.");
    else
    {
        top += 1;
        stack[top] = item;
        printf("%d pushed in the stack", item);
    }
}
void pop()
{
    if (top < 0)
        printf("Stack underflow. No element available to pop.");
    else
    {
        printf("%d popped from the stack", stack[top]);
        top -= 1;
    }
}
void display()
{
    if (top < 0)
        printf("[]");
    else
    {
        printf("\n[");
        for (int i = 0; i < top; i++)
        {
            printf("%d, ", stack[i]);
        }
        printf("%d]", stack[top]);
    }
}
void main()
{
    printf("Enter stack size: ");
    scanf("%d", &n);
    stack[n];
    printf("MENU:\n1. Push\n2. Pop\n3. Display Stack\n4. Exit");
    int choice = 0, data;
    while (choice != 4)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice. Try again.");
            break;
        }
    }
}