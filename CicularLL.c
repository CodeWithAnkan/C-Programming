#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;

    do {
        printf("Element is %d\n", ptr-> data);
        ptr = ptr->next;
    } while(ptr != head);
}

struct Node *insertAtBeginning(struct Node *head, int data){
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head-> next; // required step for the loop to traverse
    while(p->next!= head){
        p = p->next;
    }

    p->next = ptr; // becomes the first node
    ptr->next = head; // node get connected to the linked list
    head = ptr; // ptr (newnode) becomes the head
    return head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the Linked Lists in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data =3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked List before Insertion\n");
    linkedListTraversal(head);

    head = insertAtBeginning(head, 80);
    printf("Circular Linked List after Insertion\n");
    linkedListTraversal(head);

    return 0;
}