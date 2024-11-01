#include <stdio.h>
#include <stdlib.h>

// Define the structure for the nodes in the BST
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    n->data = data;                                 // Set the data value
    n->left = NULL;                                 // Set left and right child pointers to NULL
    n->right = NULL;
    return n;
}

// Function to perform in-order traversal (used to display the tree)
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to find the in-order predecessor (rightmost node in the left subtree)
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left; // Go to the left subtree
    while (root->right != NULL)
    {
        root = root->right; // Move to the rightmost node
    }
    return root; // Return the in-order predecessor
}

// Function to delete a node from the BST
struct node *DeletionBST(struct node *root, int key)
{
    struct node *iPre;

    // Base case: if the root is NULL, return NULL
    if (root == NULL)
    {
        return NULL;
    }

    // If the node to delete is a leaf node and matches the key, free it and return NULL
    if (root->left == NULL && root->right == NULL && key == root->data)
    {
        free(root);
        return NULL;
    }

    // Step 1: Traverse to find the node to delete
    if (key < root->data)
    {
        // Go to the left subtree
        root->left = DeletionBST(root->left, key); // Update the left pointer
    }
    else if (key > root->data)
    {
        // Go to the right subtree
        root->right = DeletionBST(root->right, key); // Update the right pointer
    }
    else if (root->left == NULL && root->data == key)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL && root->data == key)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }

    // Step 2: Node with key found (key == root->data)
    else
    {
        // Node has two children
        iPre = inOrderPredecessor(root);                  // Find the in-order predecessor
        root->data = iPre->data;                          // Replace the value with the in-order predecessor's value
        root->left = DeletionBST(root->left, iPre->data); // Recursively delete the in-order predecessor
    }

    return root; // Return the updated root pointer
}

int main()
{
    // Creating a sample tree
    struct node *p = createNode(10);
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(40);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(7);
    struct node *p5 = createNode(50);
    struct node *p6 = createNode(21);

    /*
           10
        /       \
        5         40
      /   \     /    \
     1     7   21      50
    */

    // Manually linking the nodes to form the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p6;
    p2->right = p5;

    // Display the tree before deletion
    printf("In-order before deletion: ");
    inOrder(p);
    printf("\n");

    // Delete node with value 28
    DeletionBST(p, 5);

    // Display the tree after deletion
    printf("In-order after deletion: ");
    inOrder(p);
    printf("\n");

    return 0;
}