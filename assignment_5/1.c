// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000

int tree[MAX_NODES];
int n = 0;

int calSum(int node)
{
    if (node >= n)
    {
        return 0;
    }
    return calSum(node * 2 + 1) + calSum(node * 2 + 2) + tree[node];
}

int isSatisfied(int node)
{
    if (node >= n || (node * 2 + 1 >= n && node * 2 + 2 >= n))
    {
        return 1;
    }
    int leftSum = calSum(node * 2 + 1);
    int rightSum = calSum(node * 2 + 2);
    if ((tree[node] == leftSum + rightSum) && isSatisfied(node * 2 + 1) && isSatisfied(node * 2 + 2))
    {
        return 1;
    }
    return 0;
}

int main()
{
    while (1)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp != -1001)
        {
            tree[n] = tmp;
        }
        else
        {
            break;
        }
        n++;
    }
    printf(isSatisfied(0) ? "True" : "False");
    return 0;
}
