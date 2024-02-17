#include <stdio.h>
struct node{
    int data;
    struct node *next;
} *top=NULL;

void push(int data){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if(newnode = NULL){
        printf("Stack overflow");
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->next = top;
    top = newnode;
}