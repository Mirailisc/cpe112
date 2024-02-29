// Phubordin Poolnai 66070501040
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

typedef struct
{
    char ch;
    int num;
    int prior;
} Element;

#define ElementType Element

int compare(const ElementType *a, const ElementType *b)
{
    if (a->prior == b->prior)
    {
        return a->num < b->num;
    }
    return a->prior > b->prior;
}

typedef struct
{
    size_t size;
    size_t capacity;
    ElementType *array;
} PriorityQueue;

PriorityQueue *priorityQueue_create()
{
    PriorityQueue *newQueue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    newQueue->capacity = 8;
    newQueue->array = (ElementType *)malloc(sizeof(ElementType) * newQueue->capacity);
    newQueue->size = 0;
    return newQueue;
}

void priorityQueue_free(PriorityQueue *queue)
{
    free(queue->array);
    free(queue);
}

void push(PriorityQueue *queue, ElementType value)
{
    if (queue->size >= queue->capacity)
    {
        queue->capacity *= 2; // double capacity
        queue->array = (ElementType *)realloc(queue->array, queue->capacity * sizeof(ElementType));
    }
    queue->array[queue->size++] = value;
    size_t index = queue->size - 1;
    while (index > 0 && compare(&(queue->array[index]), &(queue->array[(index - 1) / 2])))
    {
        ElementType temp = queue->array[index];
        queue->array[index] = queue->array[(index - 1) / 2];
        queue->array[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

int empty(PriorityQueue *queue)
{
    return (queue->size == 0);
}

void pop(PriorityQueue *queue)
{
    if (empty(queue))
    {
        fprintf(stderr, "Can't pop, priority_queue is empty.");
        exit(EXIT_FAILURE);
    }
    queue->size--;
    queue->array[0] = queue->array[queue->size];
    ElementType tmp = queue->array[0];
    size_t idx = 0;
    size_t c;
    while ((c = 2 * idx + 1) < queue->size)
    {
        if (c + 1 < queue->size && !compare(&(queue->array[c]), &(queue->array[c + 1])))
        {
            c++;
        }
        if (!compare(&(queue->array[c]), &tmp))
        {
            break;
        }
        queue->array[idx] = queue->array[c];
        idx = c;
    }
    queue->array[idx] = tmp;
}

ElementType top(PriorityQueue *queue)
{
    return queue->array[0];
}

int main()
{
    PriorityQueue *pq = priorityQueue_create();
    char input[10000];
    fgets(input, 10000, stdin);
    for (int i = 0; i < strlen(input) - 1; i++)
    {
        char buffer = input[i];
        Element newElement;
        if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z'))
        {
            if (buffer == 'a' || buffer == 'e' || buffer == 'i' || buffer == 'o' || buffer == 'u' ||
                buffer == 'A' || buffer == 'E' || buffer == 'I' || buffer == 'O' || buffer == 'U')
            {
                newElement.prior = 3;
            }
            else
            {
                newElement.prior = 1;
            }
        }
        else
        {
            newElement.prior = 2;
        }
        newElement.num = i;
        newElement.ch = buffer;
        push(pq, newElement);
    }
    while (!empty(pq))
    {
        ElementType topElement = top(pq);
        printf("%c", topElement.ch);
        pop(pq);
    }
    priorityQueue_free(pq);
    return 0;
}
