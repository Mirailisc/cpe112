#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} node;

typedef struct Graph
{
    int num;
    struct node **adjList;
} Graph;

node *createNode(int v)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->vertex = v;
    return newNode;
}

Graph *createAGraph(int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num = v;
    graph->adjList = (node **)malloc(v * sizeof(node *));
    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int s, int d)
{
    node *newNode = createNode(d);
    newNode->next = graph->adjList[s];
    graph->adjList[s] = newNode;

    newNode = createNode(s);
    newNode->next = graph->adjList[d];
    graph->adjList[d] = newNode;
}

void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->num; v++)
    {
        node *temp = graph->adjList[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(void)
{
    Graph *graph = createAGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);
    return 0;
}
