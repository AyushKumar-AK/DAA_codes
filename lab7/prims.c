#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V_MAX 100

int V, E; 
int graph[V_MAX][V_MAX]; 
int visited[V_MAX]; 
int key[V_MAX]; 
int parent[V_MAX]; 

int min_key_vertex() {
    int min_key = INT_MAX, min_key_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min_key) {
            min_key = key[v];
            min_key_index = v;
        }
    }
    return min_key_index;
}

void print_mst() {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim() {
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++) {
        int u = min_key_vertex(); 
        visited[u] = 1; 
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    print_mst();
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    prim(); 
    return 0;
}


//output
// Enter the number of vertices: 3
// Enter the number of edges: 3
// Enter the edges and their weights:
// 0 1 5
// 1 2 3
// 2 0 1
// Edge 	Weight
// 0 - 2 	1
// 1 - 0 	5
