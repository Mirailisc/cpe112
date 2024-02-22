// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insert(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (!head)
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

void reverseLinkedList(int l, int r)
{
    if (l >= r || !head)
        return;

    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    Node *before = NULL;
    Node *first = NULL;

    int index = 1;

    while (index < l && current)
    {
        before = current;
        current = current->next;
        index++;
    }

    first = current;

    while (current && index <= r)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        index++;
    }

    if (before)
        before->next = prev;
    else
        head = prev;

    first->next = current;
}

void printAllNode()
{
    Node *current = head;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    char string[10];
    int l, r;

    while (1)
    {
        scanf("%s", string);
        if (strcmp(string, "END") == 0)
        {
            break;
        }
        int value = atoi(string);
        insert(value);
    }

    scanf("%d %d", &l, &r);

    reverseLinkedList(l, r);
    printAllNode();

    return 0;
}
