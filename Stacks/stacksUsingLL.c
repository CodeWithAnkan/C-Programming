#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return -1;
    }
    else{
        return 0;
    }
    free(p);
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}

int peek(int position, struct Node* top) {
    struct Node *ptr = top;
    for (int i = 0; i < position - 1 && ptr!= NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr!= NULL)
    {
        return ptr->data;
    }    
}

int stackTop(struct Node* top) {
    if (top == NULL) {
        return -1;
    }
    else {
        return top->data;
    }
}

int stackBottom(struct Node* top) {
    if (top == NULL) {
        return -1;
    }
    else {
        struct Node* ptr = top;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        return ptr->data;
    }
}
 
int main(){
    struct Node* top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 12);
    top = push(top, 67);
    top = push(top, 34);
    top = push(top, 42);
    top = push(top, 44);
    
    linkedListTraversal(top);
    int position = 3;
    printf("\nElement at position %d is %d", position, peek(position, top));
    printf("\nStack Top: %d\n", stackTop(top));
    printf("Stack Bottom: %d\n", stackBottom(top));
    return 0;
}