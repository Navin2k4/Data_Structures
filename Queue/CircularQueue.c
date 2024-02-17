#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if (((rear + 1) % N) == front){
        printf("Queue is full");
    }
    else{
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1){
        printf("Queue is underflow");
    }
    else if (front == rear){
        front = rear = -1;
    }
    else{ 
        printf("Front : %d", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue is : ");
        while (i != rear)
        {
            printf(" %d ", queue[i]);
            i = (i + 1) % N;
        }
        printf(" %d ", queue[rear]);
    }
}
void peek()
{
    printf("%d", queue[front]);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    enqueue(8);
    display();
    dequeue();
    display();
    enqueue(15);
    display();

    return 0;
}