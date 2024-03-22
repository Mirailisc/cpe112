// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char s[MAX_SIZE];
char stk[MAX_SIZE][MAX_SIZE];
int top = -1;

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void push(char var[])
{
    strcpy(stk[++top], var);
}

void pop()
{
    top--;
}

int main()
{
    scanf("%s", s);

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            char num1[MAX_SIZE], num2[MAX_SIZE];

            strcpy(num1, stk[top]);
            pop();

            strcpy(num2, stk[top]);
            pop();

            char new[MAX_SIZE] = "";

            strcat(new, num1);
            strcat(new, num2);

            char new_operator[2] = {s[i], '\0'};

            strcat(new, new_operator);
            push(new);
        }
        else
        {
            char new[2] = {s[i], '\0'};

            push(new);
        }
    }

    printf("%s", stk[top]);

    return 0;
}
