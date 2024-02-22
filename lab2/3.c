// Phubordin Poolnai 66070501040

#include <stdio.h>

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    if (n != m)
    {
        printf("ERROR");
        return 0;
    }

    int prim = 0;
    int sec = 0;
    int buffer;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &buffer);
            if (i == j)
            {
                prim += buffer;
            }
            if (j == n - i - 1)
            {
                sec += buffer;
            }
        }
    }

    printf("Primary: %d\nSecondary: %d", prim, sec);

    return 0;
}