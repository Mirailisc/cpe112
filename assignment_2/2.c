// Phubordin Poolnai 66070501040

#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int minJumps(int arr[], int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    if (arr[start] == 0)
    {
        return -1;
    }

    int minJumpsCount = __INT_MAX__;

    for (int i = start + 1; i <= start + arr[start] && i <= end; ++i)
    {
        int jumps = minJumps(arr, i, end);

        if (jumps != -1)
        {
            minJumpsCount = min(minJumpsCount, 1 + jumps);
        }
    }

    return (minJumpsCount == __INT_MAX__) ? -1 : minJumpsCount;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int result = minJumps(arr, 0, n - 1);

    if (result != -1)
    {
        printf("%d", result);
    }
    else
    {
        printf("Not Possible");
    }

    return 0;
}
