// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void createStack(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char c)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return '\0';
}

bool isValidPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(char *s)
{
    Stack stack;
    createStack(&stack);
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(&stack, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (isEmpty(&stack) || !isValidPair(pop(&stack), s[i]))
            {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main(void)
{
    char s[MAX_SIZE + 1];
    scanf("%s", s);
    printf(isBalanced(s) ? "The string is balanced\n" : "The string is not balanced\n");
    return 0;
}
