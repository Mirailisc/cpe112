// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

void printSpiral(int **matrix, int row, int col)
{
    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
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

    printSpiral(matrix, row, col);

    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
