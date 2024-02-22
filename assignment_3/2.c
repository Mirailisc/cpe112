// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNodePtr = createNode(value);
        if (head == NULL)
        {
            head = newNodePtr;
            tail = newNodePtr;
        }
        else
        {
            tail->next = newNodePtr;
            tail = newNodePtr;
        }
    }

    int ans = 0;
    int i = 1;
    struct Node *current = head;
    while (current != NULL)
    {
        ans = (ans + k) % i;
        i++;
        current = current->next;
    }

    current = head;
    for (int j = 0; j < ans; j++)
    {
        current = current->next;
    }

    printf("%d\n", current->data);

    current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
