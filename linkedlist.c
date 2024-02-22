#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *listHead = NULL;
Node *listTail = NULL;

int size = 0;

void insertBegin(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = listHead;

    if (listHead == NULL)
    {
        listHead = newNode;
        listTail = newNode;
    }
    else
    {
        listHead = newNode;
    }

    size++;
}

void insertEnd(int value)
{
    /*
    
    */
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (listHead == NULL)
    {
        listHead = newNode;
        listTail = newNode;
    }
    else
    {
        listTail->next = newNode;
        newNode->prev = listTail;
        listTail = newNode;
    }

    size++;
}

void insertAfter(int value, int key)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    Node *ptr = listHead; // Indicates the current node
    while (ptr != NULL)
    {
        if (ptr->value == key)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
    }

    size++;
}

void insertBefore(int value, int key)
{
    /*
    head -> [1 | next] -> [2 | next] -> [3 | next] -> tail

    expect: head -> [1 | next] -> [2 | next] -> [69 | next] -> [3 | next] -> tail

    double LinkedList
    */

    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    Node *ptr = listHead; // Indicates the current node
    while (ptr != NULL)
    {
        if (ptr->value == key)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
    }

    size++;
}

void printNodes()
{
    Node *newNode = listHead;
    while (newNode != NULL)
    {
        printf("%d ", newNode->value);
        newNode = newNode->next;
    }
    printf("\n");
}

int main()
{
    int length;

    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        int value;
        scanf("%d", &value);

        insertEnd(value);
    }

    // insertAfter(69, 3);

    printNodes();

    return 0;
}