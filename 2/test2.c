#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Define an edge struct to represent an edge in the graph
typedef struct Edge {
    int to;     // destination node of the edge
    int weight; // weight of the edge
    struct Edge* next; // pointer to the next edge in the adjacency list
} Edge;

// Define a node struct to represent a node in the graph
typedef struct Node {
    Edge* edges; // pointer to the head of the adjacency list for the node
    int indegree; // number of incoming edges to the node
} Node;

int v, e; // number of nodes and edges in the graph
Node nodes[MAX_NODES + 1]; // array of nodes in the graph
int indegrees[MAX_NODES + 1]; // array of indegrees for each node
int dist[MAX_NODES + 1]; // array to store the length of the longest path to each node
int count[MAX_NODES + 1]; // array to store the number of distinct paths with the longest length to each node

int main(int argc, char *argv[]) {
    // Open input and output files
    FILE* fin = fopen(argv[1], "r");

    // Step 1: Read input from file
    fscanf(fin, "%d %d", &v, &e);
    for (int i = 1; i <= e; i++) {
        int from, to, weight;
        fscanf(fin, "%d %d %d", &from, &to, &weight);
        
        // Create a new edge and add it to the adjacency list for the "from" node
        Edge* new_edge = (Edge*) malloc(sizeof(Edge));
        new_edge->to = to;
        new_edge->weight = weight;
        new_edge->next = nodes[from].edges;
        nodes[from].edges = new_edge;

        // Update the indegree of the "to" node
        indegrees[to]++;
    }

    // Step 2: Initialize data
    int queue[MAX_NODES], front = 0, rear = 0;
    for (int i = 1; i <= v; i++) {
        if (indegrees[i] == 0) {
            // If a node has no incoming edges, add it to the queue
            queue[rear++] = i;
        }

        // Initialize the dist and count arrays to -1 and 0 respectively for each node
        dist[i] = -1;
        count[i] = 0;
    }

    // Set the dist and count values for the source node (node 1)
    dist[1] = 0;
    count[1] = 1;

    // Step 3: Perform topological sort using Kahn's algorithm
    while (front < rear) {
        // Get the next node from the queue
        int from = queue[front++];

        // Iterate over the outgoing edges from the node
        for (Edge* edge = nodes[from].edges; edge != NULL; edge = edge->next) {
            int to = edge->to;
            int weight = edge->weight;

            // If we have found a new longest path to the destination node, update the dist and count values
            if (dist[from] != -1 && (dist[to] == -1 || dist[to] < dist[from] + weight)) {
                dist[to] = dist[from] + weight;
                count[to] = count[from];
            }
            // If we have found another path with the longest length, add its count to the count of the destination node
            else if (dist[from] != -1 && dist[to] == dist[from] + weight) {
                count[to] += count[from];
            }

            // Decrement the indegree of the destination node, and add it to the queue if its indegree becomes 0
            indegrees[to]--;
            if (indegrees[to] == 0) {
                queue[rear++] = to;
            }
        }
    }

    // Step 4: Write output to file
    printf("longest path: %d\n", dist[v]);
    printf("number of longest paths: %d\n", count[v]);

    // Close input and output files
    fclose(fin);

    return 0;
}
