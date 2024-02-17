#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjacencyList;
    int *visited;
} Graph;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjacencyList = (Node **)malloc(numVertices * sizeof(Node *));
    graph->visited = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void DFS(Graph *graph, int startVertex)
{
    Node *temp = graph->adjacencyList[startVertex];
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->data;
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Graph *graph = createGraph(numVertices);

    int src, dest;
    for (int i = 0; i < numEdges; i++)
    {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the start vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex);
    printf("\n");

    return 0;
}
