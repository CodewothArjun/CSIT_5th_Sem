#include <stdio.h>
#define INF 99999
#define V 4

void printSolution(int dist[V][V]);

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int steps = 0; // Step counter

    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            steps++; // Count initialization step
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                steps++; // Step for comparison
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    steps++; // Step for update
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);

    // Print total number of steps
    printf("\nTotal Steps Executed: %d\n", steps);
}

void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {5, INF, 0,   1},
        {INF, INF, 3, 0}
    };

    floydWarshall(graph);
    return 0;
}
