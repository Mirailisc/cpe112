// Phubordin Poolnai 66070501040
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    for (int i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int V)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main()
{
    int V, src;
    scanf("%d %d", &V, &src);
    int graph[MAX_NODES][MAX_NODES];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    dijkstra(graph, src, V);

    return 0;
}
