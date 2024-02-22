// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printAllNodes(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAfter(Node *prev, int value)
{
    Node *newNode = createNode(value);
    newNode->next = prev->next;
    prev->next = newNode;
}

void insertBefore(Node **head, Node *nextNode, int value)
{
    Node *newNode = createNode(value);

    if (nextNode == *head)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        newNode->next = nextNode;

        Node *current = *head;
        Node *prev = NULL;

        while (current != NULL && current != nextNode)
        {
            prev = current;
            current = current->next;
        }

        if (prev != NULL)
        {
            prev->next = newNode;
        }
    }
}

void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; ++i)
    {
        int value;
        scanf("%d", &value);

        Node *newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    char mode;
    while (1)
    {
        scanf(" %c", &mode);

        switch (mode)
        {
        case 'A':
        {
            int r, v;
            scanf("%d%d", &r, &v);

            Node *current = head;
            while (current != NULL && current->data != r)
            {
                current = current->next;
            }

            if (current != NULL)
            {
                insertAfter(current, v);
            }
            break;
        }
        case 'B':
        {
            int previous, value;
            scanf("%d%d", &previous, &value);

            Node *current = head;
            while (current != NULL && current->data != previous)
            {
                current = current->next;
            }

            if (current != NULL)
            {
                insertBefore(&head, current, value);
            }
            break;
        }
        case 'E':
            printAllNodes(head);
            freeList(head);
            return 0;
        default:
            printf("Invalid mode\n");
            break;
        }
    }
}
