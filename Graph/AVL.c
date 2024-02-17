#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node *insert(Node *root, int value)
{
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    }
    else if (value > root->data){
        root->right = insert(root->right, value);
    }
    else{
        return root; 
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data){
        return rightRotate(root);
    }
    if (balance < -1 && value > root->right->data){
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
