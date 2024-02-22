// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -999999
#define INT_MAX 999999

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *listHead = NULL;
Node *listTail = NULL;

int size;
int k = 0;
int search[100000];

void insertNode(int value)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (listHead == NULL)
    {
        listHead = tmp;
        listTail = tmp;
    }
    else
    {
        tmp->prev = listTail;
        listTail->next = tmp;
        listTail = tmp;
    }
    size++;
}

void deleteNode(int key)
{
    Node *ptr = listHead;
    while (ptr != NULL)
    {
        if (ptr->value == key)
        {
            Node *p1 = ptr->prev;
            Node *p2 = ptr->next;
            if (size == 1)
            {
                listHead = listTail = NULL;
                size = 0;
                free(ptr);
                return;
            }
            if (ptr != listTail)
            {
                p2->prev = p1;
            }
            else
            {
                listTail = p1;
            }
            if (ptr != listHead)
            {
                p1->next = p2;
            }
            else
            {
                listHead = p2;
            }
            free(ptr);
            size--;
            return;
        }
        ptr = ptr->next;
    }
}

void searchNodes(int key)
{
    Node *ptr = listHead;
    while (ptr != NULL)
    {
        if (ptr->value == key)
        {
            search[k++] = (ptr->prev == NULL) ? INT_MIN : ptr->prev->value;
            search[k++] = (ptr->next == NULL) ? INT_MIN : ptr->next->value;
            return;
        }
        ptr = ptr->next;
    }
    search[k++] = INT_MAX;
    search[k++] = INT_MAX;
}

int main()
{
    size = 0;

    while (1)
    {
        char mode[3];
        int value;

        scanf("%s", mode);

        if (strcmp(mode, "END") == 0)
        {
            break;
        }
        else if (strcmp(mode, "ADD") == 0)
        {
            scanf("%d", &value);
            insertNode(value);
        }
        else if (strcmp(mode, "DEL") == 0)
        {
            scanf("%d", &value);
            deleteNode(value);
        }
        else
        {
            scanf("%d", &value);
            searchNodes(value);
        }
    }

    for (int j = 0; j < k; j++)
    {
        if (search[j] == INT_MIN)
        {
            printf("NULL");
        }
        else if (search[j] == INT_MAX)
        {
            printf("none");
            j++;
        }
        else
        {
            printf("%d", search[j]);
        }
        if (j & 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    if (size == 0)
    {
        printf("none");
    }

    while (listHead != NULL)
    {
        printf("%d ", listHead->value);
        listHead = listHead->next;
    }

    printf("\n");

    if (size == 0)
    {
        printf("none");
    }

    while (listTail != NULL)
    {
        printf("%d ", listTail->value);
        listTail = listTail->prev;
    }
    return 0;
}
