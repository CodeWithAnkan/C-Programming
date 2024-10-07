# Linked List Insertion #

## Case 1:
Insertion at the beginning of the linked list. In this case, we need to create a new node and make it the head of the linked list. Time Complexity -> O(1)

### Concept

1. struct Node *ptr = (struct Node *)malloc(size of(struct Node));
2. ptr->next = head;
3. head = ptr;
4. return head;

## Case 2:
Insertion at the end of the linked list. Time Complexity-> O(n)

### Concept

1. struct Node *ptr = (struct Node *)malloc(size of(struct Node));
2. p->next = ptr;
3. ptr->next = NULL;

## Case 3:
Insertion at a specific position in the linked list. Time Complexity-> O(n)

### Concept

1. struct Node *ptr = (struct Node *)malloc(size of(struct Node));
2. ptr->next = p->next;
3. p->next = ptr;

## Case 4:
Insertion after a Node. Time Complexity-> O(n)

### Concept

1. struct Node *ptr = (struct Node *)malloc(size of(struct Node));
2. ptr->next = p->next;
3. p->next = ptr;