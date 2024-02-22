// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void traverse(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertBegin(node **start, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(node **start, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*start == NULL)
    {
        *start = newNode;
    }
    else
    {
        node *ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

int main()
{
    int numNodes;
    scanf("%d", &numNodes);

    node *ll = NULL;

    int choice;
    scanf("%d", &choice);

    if (numNodes == 0)
    {
        printf("Invalid\n");
        return 0;
    }

    for (int i = 0; i < numNodes; ++i)
    {
        int val;
        scanf("%d", &val);

        if (choice == 1)
        {
            insertBegin(&ll, val);
        }
        else if (choice == 2)
        {
            insertEnd(&ll, val);
        }
        else
        {
            printf("Invalid\n");
            return 0;
        }
    }

    traverse(ll);

    return 0;
}
