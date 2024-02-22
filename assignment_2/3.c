// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

int isSymmetric(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int isSkewSymmetric(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != -matrix[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int row, col;

    scanf("%d %d", &row, &col);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (row != col)
    {
        printf("None");
    }
    else
    {
        if (isSymmetric(matrix, row, col))
        {
            printf("The matrix is symmetric");
        }
        else if (isSkewSymmetric(matrix, row, col))
        {
            printf("The matrix is skew-symmetric");
        }
        else
        {
            printf("None");
        }
    }

    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
