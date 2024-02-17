#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node *insertatlast(struct node *head, int value)
{
    struct node *temp;
    struct node *t = malloc(sizeof(struct node));
    t->data = value;
    t->next = NULL;

    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = t;
    return head;
}

struct node *delete(struct node *head, int value)
{
    struct node *pre, *temp;
    temp = head;
    while (temp->data != value){
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    free(temp);
    return head;
}

struct node *reverse(struct node *head){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next=prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct node *removeoccourance(struct node *head,int key){
    struct node *current = head;
    struct node *prev = NULL;

    while(current!=NULL){
        if(current->data == key){
            if(prev==NULL){
                head = current->next;
            }
            else{
                prev->next = current->next;
            }
            free(current);
            current=prev ? prev->next : head ;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return head;
}

struct node *insert(struct node *head,int value){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *merge(struct node *head,struct node *head2){
    struct node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head;
}

int ispali(struct node *head){
    int ispalindrome=1;

    int length = 0;
    struct node *temp = head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    int i;
    temp = head;
    struct node *prev = NULL;
    for(i=0;i<length/2;i++){
        prev=temp;
        temp=temp->next;
    }

    struct node *next = NULL;
    struct node *current = temp;
    struct node *newhead = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = newhead;
        newhead = current;
        current = next;
    }

    temp = head;
    while(newhead!=NULL){
        if(temp->data!=newhead->data){
            ispalindrome=0;
            break;
        }
        temp=temp->next;
        newhead=newhead->next;
    }

    prev->next = newhead;

    return ispalindrome;
}

void minmax(struct node *head){
    struct node *temp;
    temp = head;

    int min = temp->data;
    
    int max = temp->data;
    
    while(temp->next!=NULL){
        if(temp->data>max)
            max = temp->data;
        else if (temp->data<min)
            min = temp->data;
        temp = temp->next;
    }
    printf("\nMinimum element : %d",min);
    printf("\nMaximum element : %d", max);
}

struct node *removemiddle(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    struct node *pre = NULL;

    if (head == NULL || head->next == NULL){
        return head;
    }

    while (fast != NULL && fast->next != NULL){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (pre != NULL) {
        pre->next = slow->next;
    }

    free(slow);
    return head;
}

int main()
{
    struct node *head=NULL;
    struct node *newnode, *temp;
    int choice = 1, value;

    // do{
    //     newnode = (struct node *)malloc(sizeof(struct node));
    //     printf("Enter the value : ");
    //     scanf("%d", &newnode->data);
    //     newnode->next = NULL;
    //     if (head == NULL){
    //         head = temp = newnode;
    //     }
    //     else{
    //         temp->next = newnode;
    //         temp = newnode;
    //     }
    //     printf("Do you want to continue(0, 1)? ");
    //     scanf("%d", &choice);
    // } while (choice == 1);

    //struct node *head;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 10);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);

    printf("Linked List : ");
    display(head);
    minmax(head);

    printf("\nEnter the element to be inserted : ");
    scanf("%d", &value);
    head = insertatlast(head, value);
    display(head);

    printf("\nEnter the value to be deleted : ");
    scanf("%d", &value);
    head = delete (head, value);
    display(head);

    printf("\nReversed the List : ");
    head = reverse(head);
    display(head);

    printf("\nRemoving the occourance of the element : ");
    scanf("%d",&value);
    head = removeoccourance(head,value);
    display(head);

    printf("\nRemoving the middle element : ");
    head = removemiddle(head);
    display(head);

    printf("\nChecking if the Linked List is palindrome...");
    if (ispali(head)){
        printf("\nIt is Palindrome\n");
    }
    else{
        printf("\nIt is not Palindrome\n");
    }

    printf("\nNode 1 : ");
    display(head);

    struct node *head2;
    head2 = insert(head2, 1);
    head2 = insert(head2, 2);
    head2 = insert(head2, 3);
    head2 = insert(head2, 4);

    printf("\nNode 2 : " );
    display(head2);

    printf("\nMerged the nodes : ");
    head2 = merge(head,head2); 
    display(head);

}