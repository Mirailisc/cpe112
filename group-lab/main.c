#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int item;
    if (q->front == -1)
        printf("Queue is empty\n");
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
    return -1;
}

int isEmpty(struct Queue *q)
{
    if (q->rear == -1)
        return 1;
    return 0;
}

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    graph->adjLists = (struct Node **)malloc(n * sizeof(struct Node *));
    graph->visited = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int compareIntegers(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void BFS(struct Graph *graph, int start)
{
    struct Queue *queue = createQueue();

    graph->visited[start] = 1;
    enqueue(queue, start);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjLists[currentVertex];
        int adjVertices[MAX_VERTICES];
        int numAdjVertices = 0;
        while (temp)
        {
            adjVertices[numAdjVertices++] = temp->vertex;
            temp = temp->next;
        }
        qsort(adjVertices, numAdjVertices, sizeof(int), compareIntegers);

        for (int i = 0; i < numAdjVertices; i++)
        {
            int adjVertex = adjVertices[i];
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
        }
    }
}

void DFSUtil(struct Graph *graph, int v)
{
    graph->visited[v] = 1;

    struct Node *temp = graph->adjLists[v];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0)
        {
            DFSUtil(graph, adjVertex);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph *graph, int start)
{
    DFSUtil(graph, start);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->visited[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int u, e;
    scanf("%d", &u);
    scanf("%d", &e);

    struct Graph *graph = createGraph(u + 1);

    for (int i = 0; i < e; i++)
    {
        int source, dest;
        scanf("%d %d", &source, &dest);
        addEdge(graph, source, dest);
    }

    int startVertex;
    scanf("%d", &startVertex);

    BFS(graph, startVertex);
    printf("\n");

    for (int i = 0; i <= u; i++)
    {
        graph->visited[i] = 0;
    }

    DFS(graph, startVertex);
    printf("\n");

    return 0;
}
