#include <stdio.h>
#include <stdlib.h>

#define V_MAX 100
#define E_MAX 1000

int V, E;
int parent[V_MAX];
int rank[V_MAX];

struct Edge {
    int u, v, w;
} edges[E_MAX];

int compare(const void* a, const void* b) {
    struct Edge* edge_a = (struct Edge*)a;
    struct Edge* edge_b = (struct Edge*)b;
    return edge_a->w - edge_b->w;
}

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void join(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (rank[root_u] > rank[root_v])
        parent[root_v] = root_u;
    else if (rank[root_u] < rank[root_v])
        parent[root_u] = root_v;
    else {
        parent[root_v] = root_u;
        rank[root_u]++;
    }
}

void print_mst() {
    printf("Edge \tWeight\n");
    for (int i = 0; i < V - 1; i++)
        printf("%d - %d \t%d \n", edges[i].u, edges[i].v, edges[i].w);
}

void kruskal() {
    qsort(edges, E, sizeof(struct Edge), compare);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int mst_size = 0;
    for (int i = 0; i < E && mst_size < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            join(u, v);
            mst_size++;
        }
    }
    print_mst();
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    kruskal();
    return 0;
}

// Output:
// Enter the number of vertices: 3
// Enter the number of edges: 3
// Enter the edges and their weights:
// 0 1 1
// 1 2 2
// 0 2 3
// Edge    Weight
// 0 - 1   1
// 1 - 2   2

