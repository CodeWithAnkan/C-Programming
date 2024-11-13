/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int x = (l1 != NULL) ? l1->val : 0;                              // Use l1's value if it exists, else 0
        int y = (l2 != NULL) ? l2->val : 0;                              // Use l2's value if it exists, else 0
        int sum = carry + x + y;                                         // Sum current values and carry
        carry = sum / 10;                                                // Calculate new carry
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode)); // Create new node
        curr->next->val = sum % 10;                                      // Store digit (remainder)
        curr = curr->next;                                               // Move to next node

        if (l1 != NULL)
            l1 = l1->next; // Move to next node in l1
        if (l2 != NULL)
            l2 = l2->next; // Move to next node in l2
    }

    if (carry > 0)
    { // If carry remains, create final node
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->next->val = carry;
        curr->next->next = NULL;
    }
    else
    {
        curr->next = NULL; // End list if no carry remains
    }

    struct ListNode *result = dummyHead->next; // Skip dummy head to return result
    free(dummyHead);                           // Free memory of dummy head
    return result;
}