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

void push(int value)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("empty\n");
        return;
    }

    Node *ptr = head;
    printf("%d\n", ptr->value);

    head = head->next;
    free(ptr);
}

int top()
{
    if (head == NULL)
    {
        return -1;
    }
    return head->value;
}

int isEmpty()
{
    return (head == NULL);
}
int main()
{
    while (1)
    {
        char mode;
        scanf("%c", &mode);

        switch (mode)
        {
        case 'p':
            int value;
            scanf("%d", &value);

            push(value);
            break;

        case 'e':
            printf("%d\n", isEmpty());

            break;

        case 'o':
            pop();
            break;

        case 't':
            if (!isEmpty())
            {
                printf("%d\n", top());
            }
            else
            {
                printf("empty\n");
            }
            break;

        case 'q':
            return 0;
            break;

        default:
            break;
        }
    }
}