// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, char c)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = c;
}

char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

bool isPalindrome(const char *str)
{
    struct Stack stack;
    initialize(&stack);

    int len = strlen(str);
    int i;

    for (i = 0; i < len / 2; i++)
    {
        push(&stack, str[i]);
    }

    if (len % 2 != 0)
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i++] != pop(&stack))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char buffer[MAX_SIZE];

    scanf("%s", buffer);

    if (isPalindrome(buffer))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
