#include<stdio.h>
#include<stdlib.h>

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node and point it to the head of the list
    struct ListNode* DummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    DummyNode->next = head;

    // Initialize two pointers
    struct ListNode* left = DummyNode;
    struct ListNode* right = head;

    // Move the right pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (right == NULL) {
            free(DummyNode);  // Free DummyNode in case n is invalid (greater than list length)
            return head;       // If n is greater than the list length, do nothing
        }
        right = right->next;
    }

    // Move both pointers until right reaches the end of the list
    while (right != NULL) {
        left = left->next;
        right = right->next;
    }

    // Remove the nth node from the end
    struct ListNode* nodeToDelete = left->next;
    left->next = left->next->next;
    free(nodeToDelete);  // Free the memory of the deleted node

    // Get the new head of the list
    struct ListNode* newHead = DummyNode->next;
    free(DummyNode);  // Free the dummy node

    return newHead;
}