// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <string.h>

int size;
int change;
struct dict
{
    char value[101];
    char key[101];
};

void editdict(struct dict *dic, char *key, char *value)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(dic[i].key, key) == 0)
        {
            change = 1;
            strcpy(dic[i].value, value);
            return;
        }
    }

    strcpy(dic[size].key, key);
    strcpy(dic[size].value, value);

    size++;
}

void printdict(struct dict *dic, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
}

int main()
{
    int n;

    change = 0;

    scanf("%d", &n);

    struct dict dic[n];
    char buff1[101];
    char buff2[101];

    for (int i = 0; i < n + 1; i++)
    {
        scanf("%s %s", buff1, buff2);
        editdict(dic, buff1, buff2);
    }

    if (!change)
    {
        printf("No change\n");
    }

    printdict(dic, n);
}