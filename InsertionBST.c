#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(struct node* root){
    if (root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    static struct node *prev = NULL;
    if (root!=NULL)
    {
        if (!isBST(root->left)){
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);

    } else{
        return 1;
    }
}

struct node* iterativeSearch(struct node* root, int key){
    while (root!=NULL)
    {
        if (root->data == key){
            return root;
        }
        if (key < root->data){
            root = root->left;
        } else{
            root = root->right;
        }
    }
    return NULL;
}

void insertionBST(struct node* root, int key){
    struct node* prev = NULL;
    struct node* ptr;
    while (root!= NULL){
        prev = root;
        printf("Current node: %d, prev is now updated to: %d\n", root->data, prev->data);  // Display current node and prev update
        if (root->data == key){
            printf("%d is present in the tree", key);
            return;
        } else if (key < root->data){
            root = root->left;
        } else {
            root = root->right;
        }        
    }
    ptr = createNode(key);
    if(key < prev->data){
        prev->left = ptr;
    } else{
        prev->right = ptr;
    }
}

int main(){
    struct node *p = createNode(20);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(28);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(30);
/*
    20
    / \
   3   28
  / \   \
 1   4   30
*/

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    // printf("Pre-order: ");
    // preOrder(p);
    // printf("\n");
    // printf("Post-order: ");
    // postOrder(p);
    
/*
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
*/

    printf("Inorder Traversal: ");
    inOrder(p);
    printf("\n");
    insertionBST(p, 26);
    printf("Inorder Traversal: ");
    inOrder(p);

    return 0;
}