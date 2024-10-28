#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n){
    if(n==NULL){
        return 0;
    }
        return n->height;
}

struct node* createNode(int key){
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
};

int max(int a, int b){
    return a > b ? a : b;
}

int getBalanceFactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

struct node* rightRotate(struct node* p){
    struct node* q = p->left;
    struct node* r = q->right;

    q->right = p;
    p->left = r;

    p->height = max(getHeight(p->right), getHeight(p->left)) + 1;
    q->height = max(getHeight(q->right), getHeight(q->left)) + 1;

    return q;
}

struct node* leftRotate(struct node* q){
    struct node* p = q->right;
    struct node* r = p->left;

    p->left = q;
    q->right = r;

    p->height = max(getHeight(p->right), getHeight(p->left)) + 1;
    q->height = max(getHeight(q->right), getHeight(q->left)) + 1;

    return p;
}

struct node* insert(struct node* node, int key){
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key){
        node->left = insert(node->left, key);
    } else if (key > node->key){
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if(bf > 1 && key < node->left->key){
        return rightRotate(node);
    }
    // Right Right Case
    if(bf < -1 && key > node->right->key){
        return leftRotate(node);
    }
    // Left Right Case
    if(bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if(bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}