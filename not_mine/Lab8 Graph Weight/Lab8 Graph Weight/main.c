// Graph Implement
// EASY!
// 1002 // 1056 // 1057 // 1059 // 1081

#include <stdio.h>
#include <stdlib.h>

// ----- structs ----- //

typedef struct adjVertex
{
    int weight;
    int key;
    void *vertex;
    struct adjVertex *next;
} adjVertex;

typedef struct Vertex
{
    int key;
    struct Vertex *next;
    struct adjVertex *adjListHead;
} Vertex;

// ----- graph ----- //

void freeGraph(Vertex *vertexListHead)
{
    Vertex *ptr = vertexListHead;
    while (ptr != NULL)
    {
        adjVertex *adj = ptr->adjListHead;
        while (adj != NULL)
        {
            adjVertex *tempAdj = adj;
            adj = adj->next;
            free(tempAdj);
        }
        Vertex *tempPtr = ptr;
        ptr = ptr->next;
        free(tempPtr);
    }
}

Vertex *addVertex(int key, Vertex **vertexListHead)
{
    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->key = key;
    newVertex->next = NULL;
    newVertex->adjListHead = NULL;

    if (*vertexListHead == NULL)
        *vertexListHead = newVertex;
    else
    {
        Vertex *ptr = *vertexListHead;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newVertex;
    }
    return newVertex;
}

void addEdge(int from, int to, int weight, Vertex **vertexListHead)
{
    // check if vertex already in graph
    // if not -> create it!
    Vertex *ptrTo = *vertexListHead;
    Vertex *ptrFrom = *vertexListHead;
    while (ptrTo != NULL && ptrTo->key != to)
        ptrTo = ptrTo->next;
    while (ptrFrom != NULL && ptrFrom->key != from)
        ptrFrom = ptrFrom->next;

    if (ptrTo == NULL)
        ptrTo = addVertex(to, vertexListHead);
    if (ptrFrom == NULL)
        ptrFrom = addVertex(from, vertexListHead);

    adjVertex *newEdge = malloc(sizeof(adjVertex));
    newEdge->weight = weight;
    newEdge->key = to;
    newEdge->vertex = ptrTo;
    newEdge->next = NULL;
    if (ptrFrom->adjListHead == NULL)
        ptrFrom->adjListHead = newEdge;
    else
    {
        adjVertex *adj = ptrFrom->adjListHead;
        while (adj->next != NULL)
            adj = adj->next;
        adj->next = newEdge;
    }
}

// RECYCLE CODE
Vertex *swapVertex(Vertex *ptr1, Vertex *ptr2)
{
    Vertex *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

adjVertex *swapAdjVertex(adjVertex *ptr1, adjVertex *ptr2)
{
    adjVertex *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void sortAdjVertex(adjVertex **adjVertexListHead)
{
    // bubble sort
    adjVertex *countPtr = *adjVertexListHead;
    int n = 0;
    while (countPtr != NULL)
    {
        n++;
        countPtr = countPtr->next;
    }

    for (int i = 0; i <= n; i++)
    {
        int swap = 0;
        adjVertex **h = adjVertexListHead;
        for (int j = 0; j < n - i - 1; j++)
        {
            adjVertex *ptr = (*h)->next;
            adjVertex *prePtr = *h;
            if (prePtr->key > ptr->key)
            {
                *h = swapAdjVertex(prePtr, ptr);
                swap = 1;
            }
            else if (prePtr->key == ptr->key && prePtr->weight > ptr->weight)
            {
                *h = swapAdjVertex(prePtr, ptr);
                swap = 1;
            }
            h = &((*h)->next);
        }
        if (!swap)
        {
            break;
        }
    }
}
void sortVertex(Vertex **vertexListHead)
{
    // bubble sort
    Vertex *countPtr = *vertexListHead;
    int n = 0;
    while (countPtr != NULL)
    {
        n++;
        countPtr = countPtr->next;
    }

    for (int i = 0; i <= n; i++)
    {
        int swap = 0;
        Vertex **h = vertexListHead;
        for (int j = 0; j < n - i - 1; j++)
        {
            Vertex *ptr = (*h)->next;
            Vertex *prePtr = *h;
            if (prePtr->key > ptr->key)
            {
                *h = swapVertex(prePtr, ptr);
                swap = 1;
            }
            h = &((*h)->next);
        }
        if (!swap)
        {
            break;
        }
    }

    Vertex *ptr = *vertexListHead;
    while (ptr != NULL)
    {
        sortAdjVertex(&ptr->adjListHead);
        ptr = ptr->next;
    }
}

void printGraph(Vertex *vertexListHead)
{
    Vertex *ptr = vertexListHead;
    while (ptr != NULL)
    {
        adjVertex *adj = ptr->adjListHead;
        while (adj != NULL)
        {
            printf("%d -> %d (%d)\n", ptr->key, adj->key, adj->weight);
            adj = adj->next;
        }
        ptr = ptr->next;
    }
}

int main()
{
    Vertex *vertexListHead = NULL;

    int n, a, b, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        addEdge(a, b, w, &vertexListHead);
    }

    sortVertex(&vertexListHead);
    printGraph(vertexListHead);
    freeGraph(vertexListHead);
    return 0;
}
