#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d pushed into the stack\n", value);
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int poppedValue = ptr->arr[ptr->top];
        printf("%d popped out of the stack\n", poppedValue);
        ptr->top--;
        return poppedValue;
    }
}

struct stack *stackTraversal(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    return ptr;
}

struct stack *peek(struct stack *ptr, int index)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
    }
    else if (index < 0)
    {
        printf('Not a valid position\n');
    }
    else
    {
        printf("%d is at index %d of the stack\n", ptr->arr[index], index);
    }

    return ptr;
}

int stackBottom(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is at the bottom of the stack\n", ptr->arr[0]);
    }
    return ptr->arr[0];
}
int stackTop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is at the top of the stack\n", ptr->arr[ptr->top]);
    }
    return ptr->arr[0];
}

int main()
{
    struct stack *s;
    s->top = -1;
    s->size = 8;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 56);
    push(s, 6);
    push(s, 5);
    push(s, 74);
    push(s, 32);
    push(s, 12);
    push(s, 39);
    push(s, 29);
    push(s, 55);
    peek(s, 3);

    stackTraversal(s);

    return 0;
}