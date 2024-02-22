// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    int score;
} student;

typedef struct Node
{
    student val;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int id, int score)
{
    Node *tmp = malloc(sizeof(Node));
    if (tmp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->val.ID = id;
    tmp->val.score = score;
    tmp->next = head;
    head = tmp;
}

void swap(Node *a, Node *b)
{
    student tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

void sort(int mode)
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if ((mode == 1 && ptr1->val.score > ptr1->next->val.score) ||
                (mode == 0 && ptr1->val.ID > ptr1->next->val.ID))
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val.score);
        current = current->next;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int id, score;
        scanf("%d %d", &id, &score);
        insert(id, score);
    }

    int mode;
    scanf("%d", &mode);

    sort(mode);

    printList();

    return 0;
}
