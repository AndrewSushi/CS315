#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 2048

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

Edge *adj[MAX_NODES];
int indegrees[MAX_NODES];
int dist[MAX_NODES];
int count[MAX_NODES];

int main(int argc, char *argv[]) {
    // Open input and output files
    FILE *file = fopen(argv[1], "r");

    int n, m;
    fscanf(file, "%d %d", &n, &m);

    // Initialize adjacency lists and indegrees
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        indegrees[i] = 0;
    }

    // Read edges and build adjacency lists
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        fscanf(file, "%d %d %d", &from, &to, &weight);
        Edge *edge = (Edge *)malloc(sizeof(Edge));
        edge->to = to;
        edge->weight = weight;
        edge->next = adj[from];
        adj[from] = edge;
        indegrees[to]++;
    }

    // Topological sort using Kahn's algorithm
    int queue[MAX_NODES], front = 0, rear = 0;
    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            queue[rear++] = i;
        }
        dist[i] = -1;
        count[i] = 0;
    }
    dist[1] = 0;
    count[1] = 1;
    while (front < rear) {
        int from = queue[front++];
        for (Edge *edge = adj[from]; edge != NULL; edge = edge->next) {
            int to = edge->to;
            int weight = edge->weight;
            if (dist[from] != -1 && (dist[to] == -1 || dist[to] < dist[from] + weight)) {
                dist[to] = dist[from] + weight;
                count[to] = count[from];
            } else if (dist[from] != -1 && dist[to] == dist[from] + weight) {
                count[to] += count[from];
            }
            indegrees[to]--;
            if (indegrees[to] == 0) {
                queue[rear++] = to;
            }
        }
    }

    // Output results to output file
    printf("longest path: %d\n", dist[n]);
    printf("number of longest paths: %d\n", count[n]);

    // Close input and output files
    fclose(file);

    return 0;
}
