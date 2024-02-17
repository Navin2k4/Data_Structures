#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *next;
};

struct Node *newNode(int d, int p){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

struct Node *dequeue(struct Node *head)
{
    if (head == NULL){
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *enqueue(struct Node *head, int d, int p)
{
    struct Node *start = head;
    struct Node *temp = newNode(d, p);
    if (head == NULL || head->priority > p)
    {
        temp->next = head;
        return temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
        return head;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = newNode(3, 1);
    head = enqueue(head, 10, 2);
    head = enqueue(head, 7, 3);
    head = enqueue(head, 9, 1);
    printf("Priority Queue elements: ");
    display(head);
    printf("Dequeued element\n");
    head = dequeue(head);
    printf("Priority Queue elements after dequeue: ");
    display(head);
    return 0;
}
