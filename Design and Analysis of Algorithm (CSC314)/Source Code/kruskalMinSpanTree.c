#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (used in qsort)
int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

// Find set of an element i (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets x and y (uses union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Kruskal's algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX]; // Store MST edges
    int e = 0; // index for result[]
    int i = 0; // index for sorted edges

    // Sort edges by increasing weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for union-find subsets
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges one by one
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        // If including this edge doesn't cause a cycle, include it in MST
        if (x != y) {
            result[e++] = next;
            unionSets(subsets, x, y);
        }
    }

    // Print the result
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST = %d\n", totalWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[MAX];

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);
    return 0;
}
