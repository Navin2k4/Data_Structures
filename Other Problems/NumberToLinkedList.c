#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void displayList(struct node *head)
{
    printf("Linked list of digits: ");
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *insertend(struct node *head,int num){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next =NULL;
    if(head==NULL){
        return newnode;
    }
    struct node *temp =head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= newnode;
    return head;
}

struct node *numberofdigit(int number){
    struct node *head = NULL;
    int digit;
    while(number!=0){
        digit = number%10;
        head = insertend(head,digit);
        number/=10;
    }
    return head;
}

int main()
{
    int n;
    struct node *head;
    printf("Enter the number : ");
    scanf("%d",&n);
    head = numberofdigit(n);
    displaylist(head);
    return 0;
}