#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int capacity;
} vector;

vector create()
{
    vector new;
    new.capacity = 8;
    new.size = 0;
    new.array = malloc(sizeof(int) * new.capacity);

    return new;
}

int compare(const int *a, const int *b)
{
    return *a < *b;
}

void push(vector *pq, int val)
{
    if (pq->size == pq->capacity)
    {
        pq->capacity = pq->capacity << 1;
        pq->array = realloc(pq->array, sizeof(int) * pq->capacity);
    }

    pq->array[pq->size++] = val;
    size_t index = pq->size - 1;

    while (index > 0 && compare(&(pq->array[index]), &(pq->array[(index - 1) / 2])))
    {
        int temp = pq->array[index];
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
    int tmp = pq->array[0];
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

int top(vector *pq)
{
    return pq->array[0];
}

int main()
{
    vector adj[100][100];

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            adj[i][j] = create();
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int u, v, w;

        scanf("%d%d%d", &u, &v, &w);
        push(&adj[u][v], w);
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            while (!empty(&adj[i][j]))
            {
                printf("%d -> %d (%d)\n", i, j, top(&adj[i][j]));
                pop(&adj[i][j]);
            }
        }
    }
}