#include <stdio.h>

struct Node
{
    int value;
    struct Node *next;
};

int main()
{
    struct Node node1,node2,node3;

    node1.value = 10;
    node2.value = 20;
    node3.value = 30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct Node newNode;
    newNode.value=40;
    newNode.next=NULL;
    
    struct Node *current = &node1;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = &newNode;

    current = &node1;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL");

    return 0;
}
