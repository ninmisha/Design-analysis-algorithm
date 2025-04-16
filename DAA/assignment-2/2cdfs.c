#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];
int reachable[MAX];
int reachIndex = 0;
int n; 

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node); 
    reachable[reachIndex++] = node;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, edges, origin, destination, start, isDirected;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    for (i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter edges (origin destination):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &origin, &destination);
        graph[origin][destination] = 1;
        if (!isDirected) {
            graph[destination][origin] = 1;
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    reachIndex = 0;

    printf("Traversal order from node %d:\n", start);
    dfs(start);

    printf("\nReachable nodes from %d are:\n", start);
    for (i = 0; i < reachIndex; i++) {
        printf("%d ", reachable[i]);
    }

    return 0;
}