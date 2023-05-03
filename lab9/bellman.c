// bellman ford algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge =
        (struct Edge *)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    int i;
    for (i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    int i, j;
    for (i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }

    printArr(dist, V);

    return;
}

int main()
{
    printf("Enter the number of vertices and edges\n");
    int V, E;
    scanf("%d%d", &V, &E);
    struct Graph *graph = createGraph(V, E);
    printf("Enter the source, destination and weight of each edge\n");
    int i;
    for (i = 0; i < E; i++)
    {
        scanf("%d%d%d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }
    BellmanFord(graph, 0);

    return 0;
}

//output
// Enter the number of vertices and edges
// 2 3
// Enter the source, destination and weight of each edge
// 0 1 1
// 1 0 -1
// 0 1 2
// Vertex   Distance from Source
// 0 		 0
// 1 		 -1

