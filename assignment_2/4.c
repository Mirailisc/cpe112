// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int n, int m, int (*matrix)[m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int n1, int m1, int (*A)[m1], int n2, int m2, int (*B)[m2], int (*C)[m2])
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < m1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int n, int m, int (*matrix)[m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n1, m1, n2, m2;

    scanf("%d %d", &n1, &m1);
    int A[n1][m1];
    inputMatrix(n1, m1, A);

    scanf("%d %d", &n2, &m2);
    int B[n2][m2];
    inputMatrix(n2, m2, B);

    if (m1 != n2)
    {
        printf("Not Compatible");
        return 0;
    }

    int C[n1][m2];
    multiplyMatrices(n1, m1, A, n2, m2, B, C);

    printMatrix(n1, m2, C);

    return 0;
}
