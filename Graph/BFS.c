#include <stdio.h>
#include <stdbool.h>

#define max 10

int graph[max][max];
int visited[max];

int queue[max];
int front = -1, rear = -1;

void enqueue(int ver){
    if (rear == max - 1){
        printf("Queue overflow\n");
    }
    else{
        if (front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = ver;
    }
}

int dequeue()
{
    int element;
    if (front == -1 || front > rear){
        printf("Queue underflow\n");
        return -1;
    }
    else{
        element = queue[front];
        front++;
        return element;
    }
}

void breadthFirstSearch(int start, int nv)
{
    int i, currentver;
    for (i = 0; i < nv; i++){
        visited[i] = 0;
    }
    visited[start] = 1;

    enqueue(start);

    printf("BFS traversal starting from ver %d: ", start);

    while (front <= rear && front != -1){
        currentver = dequeue();
        printf("%d ", currentver);

        for (i = 0; i < nv; i++){
            if (!visited[i] && graph[currentver][i] == 1){
                visited[i] = 1;
                enqueue(i);
            }
        }

    }
    
    printf("\n");
}
int main()
{
    int i, j, nv;
    printf("Enter number of vertices: ");
    scanf("%d", &nv);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < nv; i++){
        for (j = 0; j < nv; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    int start;
    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);
    breadthFirstSearch(start, nv);
    return 0;
}