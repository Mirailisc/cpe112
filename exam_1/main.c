// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    int top;
    char data[15];
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, char c)
{
    if (stack->top == 15 - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

void pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    stack->data[stack->top--];
}

void display(struct Stack *stack, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", stack->data[i]);
    }
    printf("\n");
}

char peek(struct Stack *stack)
{
    return stack->data[stack->top];
}

void shortenString(char *str)
{
    int popCount, pushCount;
    struct Stack st;
    initialize(&st);

    for (int i = 0; i < strlen(str); i++)
    {

        if (pushCount == 3)
        {
            display(&st, pushCount);
        }

        if (popCount == 2)
        {
            display(&st, popCount);
        }

        if (st.data[st.top] == -1 || str[i] != st.data[st.top])
        {
            push(&st, str[i]);
            pushCount++;
        }
        else
        {
            pop(&st);
            popCount++;
        }

        if (popCount == 2)
        {
            char temp = st.data[st.top];
            pop(&st);
            push(&st, temp);
        }
    }

    printf("%c \n", peek(&st));
    display(&st, sizeof(&st));
}

int main()
{
    char text[15];

    scanf("%s", text);

    if (strlen(text) > 10)
    {
        printf("String Overflow!");
    }
    else
    {
        shortenString(text);
    }

    return 0;
}
