//Warshall implementation in c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void floydWarshall(int** graph, int vertices) {
    int i, j, k;

    // Create a 2D array to store the shortest distances between all pairs of vertices
    int** dist = (int**) malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++) {
        dist[i] = (int*) malloc(vertices * sizeof(int));
        for (j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Run the Floyd-Warshall algorithm
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between all pairs of vertices:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Create a 2D array to store the graph
    int** graph = (int**) malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++) {
        graph[i] = (int*) malloc(vertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, vertices);

    return 0;
}


// Enter the number of vertices: 4
// Enter the adjacency matrix:
// 0 5 INF 10
// INF 0 3 INF
// INF INF 0 1
// INF INF INF 0
// Shortest distances between all pairs of vertices:
// 0	5	8	9	
// INF	0	3	4	
// INF	INF	0	1	
// INF	INF	INF	0
