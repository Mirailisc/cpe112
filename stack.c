#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = 0;

void pop()
{
    if (top == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void push(int length)
{
    int value;

    scanf("%d", &value);

    if (top == length)
    {
        printf("Stack Overflow.");
        exit(0);
    }

    stack[top++] = value;
}

int isEmpty()
{
    return top <= 0;
}

void printStack()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty.\n");
        exit(0);
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void sort()
{
    for (int i = 0; i <= top; i++)
    {
        for (int j = i + 1; j <= top; j++)
        {
            if (stack[i] < stack[j])
            {
                int temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
}

int main(void)
{
    int length;

    scanf("%d", &length);

    stack = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        push(length);
    }

    printf("Before pop: ");
    printStack();

    pop();

    printf("After pop: ");
    printStack();

    printf("Before sort: ");
    printStack();

    sort();

    printf("After sort: ");
    printStack();

    free(stack);
}