#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(front ==NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void display(){
    struct node* temp;
    if(front==NULL){
        printf("The stack is empty");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue(){
    struct node* temp;
    temp=front;
    if (rear == NULL)
    {
        printf("The stack is empty");
    }
    else{
        printf("Dequeued : %d ", temp->data);
        front = front->next;
        free(temp);
    }
}

void peek(){
    printf("Top Value :%d",rear->data);
}

int main(){
    enqueue(5);
    enqueue(10);
    enqueue(12);
    display();
    dequeue();
    peek();
    return 0;
}
