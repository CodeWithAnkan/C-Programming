# Cases of Deletion

## 1. Deleting the first node
struct node *ptr = head;
head = head -> next;
free(ptr);

## 2. Deleting a node in the middle
index = 2;
struct node *ptr = head;
while () {
    ptr = ptr -> next;
    }
    struct node *q = ptr -> next;
    ptr -> next = q -> next;
    free(q);

## 3. Deleting the last node
Traverse till q -> next = p -> next = NULL;
free(q);

## 4. Delete a node with a given value
