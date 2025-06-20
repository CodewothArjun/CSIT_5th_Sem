#include <stdio.h>
#include <limits.h>

#define V 5   // Number of vertices in the graph
#define INF 99999

// Find the vertex with minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the distance array
void printSolution(int dist[], int src) {
    printf("Vertex\t\tDistance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[V][V], int src) {
    int dist[V];       // Output array: dist[i] will hold the shortest distance from src to i
    int visited[V];    // visited[i] will be true if vertex i is included in shortest path tree

    // Initialization
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;  // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        // Update dist[v] only if not visited and path through u is shorter
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the result
    printSolution(dist, src);
}

// Main function
int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 20, 0, 60},
        {0, 0, 0, 0, 0}
    };

    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    dijkstra(graph, source);
    return 0;
}
