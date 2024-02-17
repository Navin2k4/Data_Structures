// Inorder - left root right
// preorder - root left right
// Postorder - left right root

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf(" Enter data (-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)  {   return NULL;  }
    newnode->data = x;
    printf("Left child of %d", x);
    newnode->left = create();
    printf("Right child of %d", x);
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root)
{
    if (root != NULL){
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void inorder(struct node *root)
{
    if (root != NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
    return;
}

void postorder(struct node *root)
{
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
    return;
}

void main()
{
    struct node *root;
    root = create(); // it should return the pointer of the struct node
    printf("Inorder traversal : ");
    inorder(root);
    printf("\nPreorder traversal : ");
    preorder(root);
    printf("\nPostorder traversal : ");
    postorder(root);
}