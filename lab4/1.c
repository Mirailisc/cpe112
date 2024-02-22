// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

int top = 0;
int *stack;
int capacity;

void push()
{
    int value;

    scanf("%d", &value);

    if (top == capacity)
    {
        printf("Stack Overflow.");
        exit(0);
    }
    stack[top++] = value;
}

void pop()
{
    if (top == 0)
    {
        printf("Stack Underflow.");
        exit(0);
    }
    top--;
}

int isEmpty()
{
    return top <= 0;
}

void show()
{
    if (top == 0)
    {
        printf("Stack is empty.");
        exit(0);
    }
    while (!isEmpty())
    {
        printf("%d\n", stack[--top]);
    }
}

int main()
{
    scanf("%d", &capacity);

    if (capacity <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }

    stack = (int *)malloc(capacity * sizeof(int));

    while (1)
    {
        int choice;

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            return 0;
        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
            return 0;
        }
    }
}
