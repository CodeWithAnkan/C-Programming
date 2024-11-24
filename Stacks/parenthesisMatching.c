#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char exp)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = exp;
        printf("%c pushed into the stack\n", exp);
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
        char poppedValue = ptr->arr[ptr->top];
        printf("%c popped out of the stack\n", poppedValue);
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
/*
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
*/

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

int parenthesisMatching(char *exp)
{
    struct stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *exp = "8)*(9";
    if (parenthesisMatching(exp))
    {
        printf("The parenthesis is matching");
    }
    else {
        printf("The parenthesis is not matching");
    }

    return 0;
}