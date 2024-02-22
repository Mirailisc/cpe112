// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void deleteFirstNode(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLastNode(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    free(current);
    if (previous != NULL)
    {
        previous->next = NULL;
    }
    else
    {
        *head = NULL;
    }
}

void deleteNodeWithValue(Node **head, int value)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == value)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL)
    {
        previous->next = current->next;
        free(current);
    }
}

void printAllNodes(Node *head)
{
    if (head == NULL)
    {
        printf("none\n");
        return;
    }
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    int numNodes, value, key;
    char mode;

    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    while (1)
    {
        scanf(" %c", &mode);

        if (mode == 'E')
        {
            printAllNodes(head);
            break;
        }
        else if (mode == 'F')
        {
            deleteFirstNode(&head);
        }
        else if (mode == 'L')
        {
            deleteLastNode(&head);
        }
        else if (mode == 'N')
        {
            scanf("%d", &key);
            deleteNodeWithValue(&head, key);
        }
    }

    return 0;
}
