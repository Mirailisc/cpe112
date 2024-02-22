// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertNode(Node **head, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

void deleteNode(Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    do
    {
        if (temp->data == key)
        {
            if (prev == NULL)
            {
                Node *last = *head;
                while (last->next != *head)
                {
                    last = last->next;
                }

                if (*head == (*head)->next)
                {
                    free(temp);
                    *head = NULL;
                }
                else
                {
                    *head = temp->next;
                    last->next = *head;
                }
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != *head);

    return;
}

void printAllList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }

    Node *current = head;

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main()
{
    Node *head = NULL;
    char command;
    int x;
    int memoryFreed = 0;

    while (1)
    {
        scanf(" %c", &command);

        switch (command)
        {
        case 'I':
            scanf("%d", &x);
            insertNode(&head, x);
            break;
        case 'D':
            scanf("%d", &x);
            deleteNode(&head, x);
            break;
        case 'E':
            printAllList(head);
            memoryFreed = 1;
            break;
        }

        if (command == 'E')
        {
            break;
        }
    }

    if (!memoryFreed)
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
