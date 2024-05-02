#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ff;
    int ss;
} pair;

#define type pair

typedef struct
{
    type *array;
    int size;
    int capacity;
} vector;

vector create()
{
    vector new;
    new.capacity = 8;
    new.size = 0;
    new.array = malloc(sizeof(type) * new.capacity);
    return new;
}

int compare(const type *a, const type *b)
{
    return a->ss <= b->ss;
}

void push(vector *pq, type val)
{
    if (pq->size == pq->capacity)
    {
        pq->capacity = pq->capacity << 1;
        pq->array = realloc(pq->array, sizeof(type) * pq->capacity);
    }

    pq->array[pq->size++] = val;
    size_t index = pq->size - 1;

    while (index > 0 && compare(&(pq->array[index]), &(pq->array[(index - 1) / 2])))
    {
        type temp = pq->array[index];
        pq->array[index] = pq->array[(index - 1) / 2];
        pq->array[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

int empty(vector *pq)
{
    return pq->size == 0;
}

void pop(vector *pq)
{
    pq->size--;
    pq->array[0] = pq->array[pq->size];
    type tmp = pq->array[0];
    size_t idx = 0;
    size_t c;

    while ((c = 2 * idx + 1) < pq->size)
    {
        if (c + 1 < pq->size && !compare(&(pq->array[c]), &(pq->array[c + 1])))
        {
            c++;
        }
        if (!compare(&(pq->array[c]), &tmp))
        {
            break;
        }
        pq->array[idx] = pq->array[c];
        idx = c;
    }

    pq->array[idx] = tmp;
}

type top(vector *pq)
{
    return pq->array[0];
}

int main()
{
    int n, s;

    scanf("%d%d", &n, &s);

    int adj[n][n];

    vector pq = create();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int dist[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 999999;
    }

    pair start;
    start.ff = s;
    start.ss = 0;
    dist[s] = 0;

    push(&pq, start);

    while (!empty(&pq))
    {
        pair pqtop = top(&pq);

        pop(&pq);
        int u = pqtop.ff;

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 0)
            {
                continue;
            }
            if (dist[v] > dist[u] + adj[u][v])
            {
                dist[v] = dist[u] + adj[u][v];
                pair pi = {.ff = v, .ss = dist[v]};
                push(&pq, pi);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i, dist[i]);
    }
}