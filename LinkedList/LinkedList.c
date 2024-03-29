#include <stdio.h>
#include <conio.h>

struct Node
{
    int value;
    struct Node *next;
};

int main()
{
    struct Node node1, node2, node3;

    node1.value = 10;
    node2.value = 20;
    node3.value = 30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct Node *pointer = &node1;
    while (pointer != NULL)
    {
        printf("%d -> ", pointer->value);
        pointer = pointer->next;
    }

    printf("NULL");
    return 0;
}


