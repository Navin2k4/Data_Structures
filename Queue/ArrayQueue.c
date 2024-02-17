#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void createQueue(int queue[], int size) {
    front = 0;
    rear = size - 1;
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }
}

void enqueue(int queue[], int num, int size) {
    if (rear == size - 1) {
        printf("Queue is overflow. Cannot enqueue.\n");
    } else {
        queue[++rear] = num;
    }
    printf("\n");
}

void dequeue(int queue[], int size) {
    if (front > rear) {
        printf("Queue is underflow\n");
    } else {
        printf("%d", queue[front++]);
    }
    printf("\n");
}

void isEmpty() {
    if (front > rear) {
        printf("The Queue is empty.\n");
    } else {
        printf("The Queue is not empty.\n");
    }
}

void frontPeek(int queue[]) {
    printf("%d\n", queue[front]);
    printf("\n");
}

void rearPeek(int queue[]) {
    printf("%d\n", queue[rear]);
    printf("\n");
}

void display(int queue[]) {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
    int queue[size];
    createQueue(queue, size);
    display(queue);
    printf("\nFront : ");
    frontPeek(queue);
    printf("Rear : ");
    rearPeek(queue);
    isEmpty();
    printf("\nDequeued : ");
    dequeue(queue, size);
    display(queue);
    printf("Enter the element to insert : ");
    int num;
    scanf("%d", &num);
    enqueue(queue, num, size);
    display(queue);
    return 0;
}
