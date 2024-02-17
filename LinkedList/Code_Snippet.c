#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head;

void display(struct Node *head, int num)
{
    struct Node *pointer = head;
    while (pointer != NULL)
    {
        printf("%d -> ", pointer->data);
        pointer = pointer->next;
    }
    printf("NULL");
}

void create(struct Node *head,int num){
    struct Node *temp;
    head = malloc(sizeof(struct Node));
    head->data = num;
    head->next = NULL;
    temp=head;
    scanf("%d",&num);
    do
    {
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->data = num;
        scanf("%d", &num);
    } while (num!=0);
    temp->next = NULL;
    display(head,num);
}

void ins_first(struct Node *head,int num)
{
    struct Node *temp;                     
    temp = malloc(sizeof(struct Node));       
    temp->data = num;                      
    temp->next = head;                     
    head = temp;
    display(head, num);
}

void ins_last(struct Node *head,int num){
    struct Node *temp,*ptr;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr = malloc(sizeof(struct Node));
    ptr->data = num;
    ptr->next = NULL;
    display(head, num);
}

void ins_middle(struct Node *head,int num, int num1){
    struct Node *temp,*ptr;
    temp=malloc(sizeof(struct Node));
    temp->data=num;
    ptr=head;
    while(ptr->data!=num1){
        ptr=ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    display(head, num);
}

void del_first(struct Node *head){
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}

void del_last(struct Node *head){
    struct Node *temp,*ptr;
    temp = head ;
    while(temp->next != NULL){
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
}

void del_mid(struct Node *head,int num){
    struct Node *temp,*ptr;
    temp = head;
    while(temp->data!=num){
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);
    display(head, num);
}

void isempty(struct Node *head){
    if(head == NULL){printf("Then node is Empty");}
    else{printf("The node is not Empty");}
}

int num_nodes(struct Node *head){
    int count=0;
    struct Node *temp;
    temp = head;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    printf("The Number of nodes is %d",num_nodes);
    return count;
}

void search(struct Node *head,int num){
    struct Node *temp;
    temp=head;
    int flag = 0;
    while(temp->next!=NULL){
        if(temp->data=num){
            printf("Number Found");
            flag = 1;
            break;
        }
        else{
            temp=temp->next;
        }
    }
    if(flag == 0){
        printf("Number Not Found");
    }
}


//!!Code yet to be completed below part 

void main(){
    struct Node *head;
    int num;
    int num1;
    int choice;
    printf("1.Create\n2.Insert at first\n3.Insert at last\n4.Insert at middle\n5.Delete at first\n6.Delete at last\n7.Delete at middle\n8.Is Empty?\n9.Search"); 
    printf("\nEnter the choice : ");
    scanf("%d",choice);
    switch (choice)
    {
    case '1':
        printf("Enter the first element of the node : ");
        scanf("%d", &num);
        create(head, num);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;

    default:
        break;
    }
}














