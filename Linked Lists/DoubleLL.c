#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* createNode(int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

int main(){
    struct node* head;
    struct node* first;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head = createNode(25);
    first = createNode(30);
    second = createNode(35);
    third = createNode(40);
    fourth = createNode(45);

    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("%d", fourth->prev->data);

    return 0;
}