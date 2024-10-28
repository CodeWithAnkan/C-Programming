#include<stdio.h>
#include<stdlib.h>

#define SIZE 10 // Size of the array

// Define structure for two stacks
struct TwoStacks{
    int arr[SIZE]; // Array to store both the stacks
    int top1; // Top pointer for stack 1
    int top2; // Top pointer for stack 2
};

void initialize(struct TwoStacks* ts){
    ts->top1 = -1; //Stack starts from index -1 (empty)
    ts->top2 = SIZE; // Stack 2 starts from the end (size of the array)
}

void push1(struct TwoStacks* ts, int x){
    // Check if the Stack 1 has reached its maximum allocated Space
    if (ts->top1 < (SIZE/2) -1){
        ts->top1++; // Increment Top1 to point to the next available position
        ts->arr[ts->top1] = x; // Insert the element into the Stack 1
        printf("Pushed %d into Stack 1\n", x);
    }
    else{
        // Stack 1 overflow
        printf("Stack Overflow in Stack 1\n");
    }
}

void push2(struct TwoStacks* ts, int x){
    // Check if the Stack 2 has reached its maximum allocated Space
    if (ts->top2 > SIZE / 2){
        ts->top2--; // Decrement Top2 to point to the next available position
        ts->arr[ts->top2] = x;
        printf("Pushed %d into Stack 2\n", x);
    } else{
        printf("Stack overflow in Stack 2\n");
    }
}

// Function to display Stack 1 (testing purpose)
void displayStack1(struct TwoStacks* ts){
    if(ts->top1 == -1){
        printf("Stack 1 is empty\n");
    } else{
        printf("Stack 1 elements: ");
        for (int i = 0; i <= ts->top1; i++)
        {
            printf("%d\t", ts->arr[i]);
        }
        printf("\n");
    }
}

// Function to display Stack 2 (for testing purpose)
void displayStack2(struct TwoStacks* ts){
    if(ts->top1 == SIZE){
        printf("Stack 2 is empty\n");
    } else{
        printf("Stack 2 elements: ");
        for (int i = SIZE - 1; i >= ts->top2; i--)
        {
            printf("%d\t", ts->arr[i]);
        }
        printf("\n");
    }
}

// Main function to test push1
int main(){
    struct TwoStacks ts;
    initialize(&ts); // Initialize the two stacks;

    // Push elements into Stack 1
    push1(&ts, 5);
    push1(&ts, 10);
    push1(&ts, 15);
    push1(&ts, 20);
    push1(&ts, 25); // This should fill Stack 1 (because SIZE/2 = 5)

    // Try pushing another elements after Stack 1 is full
    push1(&ts, 30); // Should trigger Stack Overflow

    // Push elements into Stack 2
    push2(&ts, 50);
    push2(&ts, 40);
    push2(&ts, 30);
    push2(&ts, 20);
    push2(&ts, 10);  // Fill Stack 2 (because SIZE/2 = 5)

    push2(&ts, 80); // Overflow in Stack 2
    // Display the elements of Stack 1
    displayStack1(&ts);
    displayStack2(&ts);

    return 0;
}