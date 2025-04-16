#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n; // number of nodes
int reachable[MAX]; // to store reachable nodes
int reachIndex = 0;

void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start) {
    int i, current;
    enqueue(start);
    visited[start] = 1;

    printf("Traversal order from node %d:\n", start);
    while (front <= rear) {
        current = dequeue();
        printf("%d ", current); // Traversal order
        reachable[reachIndex++] = current;

        for (i = 1; i <= n; i++) {
            if (graph[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");

    printf("Reachable nodes from %d are:\n", start);
    for (i = 0; i < reachIndex; i++) {
        printf("%d ", reachable[i]);
    }
    printf("\n");
}

int main() {
    int i, edges, origin, destination, start, isDirected;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // Initialize graph
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

    // Initialize visited and reachable arrays
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    reachIndex = 0;

    bfs(start);

    return 0;
}