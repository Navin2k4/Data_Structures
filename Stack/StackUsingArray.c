#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX_SIZE - 1);
}

void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow: Cannot push to a full stack\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return -1;
    }
    else
    {
        int item = stack[top];
        top--;
        return item;
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1; 
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop()); 

    return 0;
}
