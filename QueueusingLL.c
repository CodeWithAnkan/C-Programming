#include<stdio.h>
#include<stdlib.h>

struct node* front = NULL;
struct node* rear = NULL;

struct node {
    int data;
    struct node* next;
};

void enqueue(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Memory error\n");
    } else {
        new_node->data = data;
        new_node->next = NULL;
    if (front == NULL){
            front = rear = new_node;
    } else {
            rear->next = new_node;
            rear = new_node;
        }  
    }
}

int dequeue(){
    int value = -1;
    struct node* ptr = front;
    if (front == NULL){
        printf("Queue is empty\n");
    } else {
        front = front->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
    
}

void linkedListTraversal(struct node* ptr){
    printf("Printing the elements of this linked list\n");
    while (ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    enqueue(34);
    enqueue(4);
    enqueue(7);
    linkedListTraversal(front);
    dequeue();
    linkedListTraversal(front);

    return 0;
}