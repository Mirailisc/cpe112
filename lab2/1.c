// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

void printArrayElements(int *arr, int size, int mode)
{
    int length;
    int start = (mode == 0) ? 0 : 1;

    for (int i = mode; i < size; i += 2)
    {
        length++;
    }

    if (size == 0 || length == 0 || (mode == 1 && size % 2 != 0))
    {
        printf("none");
    }

    for (int i = start; i < size; i += 2)
    {
        printf("%d ", *(arr + i));
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    int *ptr = arr;

    for (int i = 0; i < size; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }

    int mode;
    scanf("%d", &mode);

    printArrayElements(arr, size, mode);

    free(arr);

    return 0;
}
