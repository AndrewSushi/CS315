#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct Edge{
    int to;
    int weight;
    struct Edge *next;
} Edge;

Edge *adjList[MAX_NODES];
int inDegrees[MAX_NODES];
int dist[MAX_NODES];
int count[MAX_NODES];

int main(){

    // Get the verteces and edges
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    // Initialize the Adjacency List and In Degrees List
    for(int i = 0; i < vertices; i++){
        adjList[i] = NULL;
        inDegrees[i] = 0;
    }

    // Build the Adjacency List and In Degrees List
    for(int i = 0; i < edges; i++){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        Edge *edge = (Edge *)malloc(sizeof(Edge));
        edge->to = to;
        edge->weight = weight;
        edge->next = adjList[from];
        adjList[from] = edge;
        inDegrees[to]++;
    }

    // Perform Topological Sort using Khan's Algorithm 
    int queue[MAX_NODES], front = 0, rear = 0;
    for(int i = 1; i <= vertices; i++){
        if(inDegrees[i] == 0){
            queue[rear++] = i;
        }
        dist[i] = -1;
        count[i] = 0;
    }
    dist[1] = 0;
    count[1] = 1;
    while(front < rear){
        int from = queue[front++];
        for(Edge *edge = adjList[from]; edge != NULL; edge = edge->next){
            int to = edge->to;
            int weight = edge->weight;
            if(dist[from] != -1 && (dist[from] == -1 || dist[to] < dist[from] + weight)){
                dist[to] = dist[from] + weight;
                count[to] = count[from];
            }else if(dist[from] != -1 && dist[to] == dist[from] + weight){
                count[to] += count[from];
            }
            inDegrees[to]--;
            if(inDegrees[to] == 0){
                queue[rear++] = to;
            }
        }
    }

    // Printing the Result
    printf("longest path: %d\n", dist[vertices]);
    printf("number of longest paths: %d\n", count[vertices]);
    return 0;
}