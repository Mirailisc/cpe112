#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int source;
    int destination;
    int weight;
    struct Edge *next;
} Edge;

Edge *createEdge(int source, int destination, int weight)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));

    if (newEdge == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newEdge->source = source;
    newEdge->destination = destination;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Edge *graph[], int source, int destination, int weight)
{
    Edge *newEdge = createEdge(source, destination, weight);
    newEdge->next = graph[source];
    graph[source] = newEdge;
}

void printGraph(Edge *graph[], int totalNodes)
{
    for (int i = 0; i < totalNodes; i++)
    {
        Edge *current = graph[i];
        while (current != NULL)
        {
            printf("%d —> %d (%d)\n", current->source, current->destination, current->weight);
            current = current->next;
        }
    }
}

int main()
{
    int totalLines;
    scanf("%d", &totalLines);

    Edge *graph[totalLines];
    for (int i = 0; i < totalLines; i++)
    {
        graph[i] = NULL;
    }

    for (int i = 0; i < totalLines; i++)
    {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        addEdge(graph, source, destination, weight);
    }

    printGraph(graph, totalLines);

    for (int i = 0; i < totalLines; i++)
    {
        Edge *current = graph[i];
        while (current != NULL)
        {
            Edge *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
