#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        // Step 1: Save the next node
        next = current->next;
        // Step 2: Reverse the current node's pointer
        current->next = prev;
        // Step 3: Move prev and current one step forward
        prev = current;
        current = next;
    }
    return prev; // prev becomes the new head of the reversed list
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original Linked List:\n");
    printList(head);

    // Reversing the linked list
    head = reverseLinkedList(head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}