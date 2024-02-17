#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *insert(struct node *head,int value){
    struct node *newnode = create(value);
    struct node *temp = head;
    if(head==NULL){
        newnode->next = newnode;
        return newnode;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return head;
}

int main(){
    int num,digit;
    printf("Enter the n number digit to split : ");
    scanf("%d",&num);
    struct node *head = NULL;
    while(num>0){
        digit = num %10;
        head = insert(head,digit);
        num/=10;
    }
    struct node *temp = head;

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    return 0;
}