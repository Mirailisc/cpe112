// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 1001

char stack[STACK_SIZE];
int top = -1;

void push(char val)
{
    if (top < STACK_SIZE - 1)
    {
        stack[++top] = val;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void pop()
{
    if (top >= 0)
    {
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        return '\0';
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int main()
{
    char expression[STACK_SIZE];
    char output[STACK_SIZE];
    int outputLen = 0;

    scanf("%s", expression);

    int length = strlen(expression);

    for (int i = 0; i < length; i++)
    {
        char currentChar = expression[i];

        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            output[outputLen++] = currentChar;
        }
        else if (currentChar == '(')
        {
            push(currentChar);
        }
        else if (currentChar == ')')
        {
            while (top >= 0 && peek() != '(')
            {
                output[outputLen++] = peek();
                pop();
            }
            pop();
        }
        else
        {
            while (top >= 0 && precedence(currentChar) <= precedence(peek()) && peek() != '(')
            {
                output[outputLen++] = peek();
                pop();
            }
            push(currentChar);
        }
    }

    while (top >= 0)
    {
        output[outputLen++] = peek();
        pop();
    }

    output[outputLen] = '\0';

    printf("%s\n", output);

    return 0;
}
