// Phubordin Poolnai 66070501040
#include <stdio.h>
#include <stdlib.h>

int queueSize;
int *queue;
int front = -1, rear = -1;

void insert(int val)
{
    if ((front == 0 && rear == queueSize - 1) || (front == rear + 1))
    {
        printf("Queue is full!!\n");
        return;
    }
    rear++;
    if (rear >= queueSize)
    {
        rear = 0;
    }
    queue[rear] = val;
    if (front == -1)
    {
        front = 0;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("%d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
        if (front >= queueSize)
        {
            front = 0;
        }
    }
}

void show()
{
    if (front == -1)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n", front);
    int r = rear;
    int l = front;
    printf("Items:");
    while (1)
    {
        if (l == r)
        {
            printf(" %d \n", queue[l]);
            break;
        }
        printf(" %d", queue[l]);
        l++;
        if (l >= queueSize)
        {
            l = 0;
        }
    }
    printf("Rear: %d\n", rear);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    queueSize = n;
    queue = (int *)malloc(sizeof(int) * n);
    char c;
    while (1)
    {
        scanf(" %c", &c);
        if (c == 'E')
        {
            break;
        }
        else if (c == 'I')
        {
            int val;
            scanf(" %d", &val);
            insert(val);
        }
        else if (c == 'D')
        {
            dequeue();
        }
        else if (c == 'S')
        {
            show();
        }
    }
    free(queue);
    return 0;
}
