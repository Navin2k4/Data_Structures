#include <stdio.h>
#include <stdbool.h>
#define max 10

int graph[max][max];
int visited[max];

void dfs(int start, int nv)
{
    int i;
    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < nv; i++){
        if (!visited[i] && graph[start][i] == 1){
            dfs(i, nv);
        }
    }
}

int main()
{
    int i, j, nv;
    printf("Enter number of vertices : ");
    scanf("%d", &nv);

    printf("Enter adjacency matrix (in matrix form 0/1):\n");
    for (i = 0; i < nv; i++){
        for (j = 0; j < nv; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int start;

    printf("Enter starting ver for traversal: ");
    scanf("%d", &start);

    printf("DFS traversal starting from ver %d: ", start);

    for (i = 0; i < nv; i++)
    {
        visited[i] = 0;
    }

    dfs(start, nv);
    printf("\n");

    return 0;
}
