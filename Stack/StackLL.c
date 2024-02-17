#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node *push(struct node *top, int value)
{
    if (top == NULL){
        return create(value);
    }
    struct node *newNode = create(value);
    if (newNode != NULL){
        newNode->next = top;
        top = newNode;
    }
    return top;
}

struct node *pop(struct node *top)
{
    if (top == NULL){
        printf("\nStack is empty.");
        return NULL;
    }
    struct node *temp = top;
    top = top->next;
    printf("\nPopped value is : %d ", temp->data);
    free(temp);
    return top;
}

void peek(struct node *top)
{
    if (top == NULL){
        printf("\nStack is empty.");
        return;
    }
    printf("\nThe value at the top position is : %d", top->data);
}

void display(struct node *top)
{
    printf("\n");

    struct node *current = top;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    display(top);
    top = pop(top);
    display(top);
    peek(top);
    display(top);

    return 0;
}
