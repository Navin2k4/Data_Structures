#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
void InsertAtFirst(struct Node **head, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = x;
    newNode->next = *head;
    *head = newNode;
}
void InsertAtLast(struct Node **head, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = x;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void InsertAtMiddle(struct Node **head, int pos, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = x;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        for (int i = 1; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            newNode->next = current->next;
            current->next = newNode;
        }

    }
}
int main()
{
    struct Node *head = NULL;
    int choice, num, position;

    printf("Enter the number of nodes: ");
    int numNodes;
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &num);
        InsertAtLast(&head, num);
    }
    do
    {
        printf("\n1. Display Linked List\n2. Insert at First\n3. Insert at Middle\n4. Insert at Last\n0. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("\nEnter the element to be inserted at first: ");
            scanf("%d", &num);
            InsertAtFirst(&head, num);
            display(head);
            break;
        case 3:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position to be inserted: ");
            scanf("%d", &position);
            InsertAtMiddle(&head, position, num);
            display(head);
            break;
        case 4:
            printf("\nEnter the element to be inserted at last: ");
            scanf("%d", &num);
            InsertAtLast(&head, num);
            display(head);
            break;
        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 0);

    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
