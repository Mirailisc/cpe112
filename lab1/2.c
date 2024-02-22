// Phubordin Poolnai 66070501040

#include <stdio.h>

void getSet(int *set, int *size)
{
    int prev = 0, index = 0;

    for (int i = 0; i < *size; i++)
    {
        if (set[i] != prev)
        {
            set[index] = set[i];
            prev = set[i];
            index++;
        }
    }
    *size = index;
}

void getSet2(int *set, int *size, int m, int n)
{
    int prev = 0, index = 0;

    for (int i = 0; i < *size; i++)
    {
        if (set[i] != prev && set[i] >= m && set[i] <= n)
        {
            set[index] = set[i];
            prev = set[i];
            index++;
        }
    }
    *size = index;
}

void Sort(int *set, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (set[i] > set[j])
            {
                temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }
}

void Union(int A[], int B[], int sizeA, int sizeB)
{
    int C[sizeA + sizeB];
    int sizeC = sizeA + sizeB;

    for (int i = 0; i < sizeA; i++)
    {
        C[i] = A[i];
    }

    for (int i = 0; i < sizeB; i++)
    {
        C[i + sizeA] = B[i];
    }

    Sort(C, sizeC);
    getSet(C, &sizeC);

    for (int i = 0; i < sizeC; i++)
    {
        printf("%d ", C[i]);
    }

    if (sizeC == 0)
    {
        printf("empty");
    }
}

void Intersection(int A[], int B[], int sizeA, int sizeB)
{
    int C[sizeA > sizeB ? sizeA : sizeB];
    int sizeC = 0;

    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if (A[i] == B[j])
            {
                C[sizeC] = A[i];

                sizeC++;

                break;
            }
        }
    }

    for (int i = 0; i < sizeC; i++)
    {
        printf("%d ", C[i]);
    }

    if (sizeC == 0)
    {
        printf("empty");
    }
}

void Difference(int A[], int B[], int sizeA, int sizeB)
{
    int C[sizeA];
    int sizeC = 0;

    for (int i = 0; i < sizeA; i++)
    {
        int found = 0;

        for (int j = 0; j < sizeB; j++)
        {
            if (A[i] == B[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            C[sizeC] = A[i];
            sizeC++;
        }
    }

    for (int i = 0; i < sizeC; i++)
    {
        printf("%d ", C[i]);
    }

    if (sizeC == 0)
    {
        printf("empty");
    }
}

void Complement(int A[], int sizeA, int m, int n)
{
    for (int i = m; i <= n; i++)
    {
        int found = 0;

        for (int j = 0; j < sizeA; j++)
        {
            if (A[j] == i)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("%d ", i);
        }
    }

    if (sizeA == n - m + 1)
    {
        printf("empty");
    }
}

int main()
{
    int m, n, sizeA, sizeB;

    scanf("%d %d", &m, &n);
    scanf("%d", &sizeA);

    int A[sizeA];

    for (int i = 0; i < sizeA; i++)
    {
        scanf("%d", &A[i]);
    }

    getSet2(A, &sizeA, m, n);
    scanf("%d", &sizeB);

    int B[sizeB];

    for (int i = 0; i < sizeB; i++)
    {
        scanf("%d", &B[i]);
    }

    getSet2(B, &sizeB, m, n);

    for (int i = 0; i < sizeA; i++)
    {
        printf("%d ", A[i]);
    }

    if (sizeA == 0)
    {
        printf("empty");
    }

    printf("\n");

    for (int i = 0; i < sizeB; i++)
    {
        printf("%d ", B[i]);
    }

    if (sizeB == 0)
    {
        printf("empty");
    }

    printf("\n");
    Union(A, B, sizeA, sizeB);

    printf("\n");
    Intersection(A, B, sizeA, sizeB);

    printf("\n");
    Difference(A, B, sizeA, sizeB);

    printf("\n");
    Difference(B, A, sizeB, sizeA);

    printf("\n");
    Complement(A, sizeA, m, n);

    printf("\n");
    Complement(B, sizeB, m, n);
}
