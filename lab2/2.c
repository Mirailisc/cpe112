// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

void printResult(int value, int index) {
    printf("%d %d\n", value, index);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int max = *arr, min = *arr;
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
            maxIndex = i;
        }

        if (*(arr + i) < min) {
            min = *(arr + i);
            minIndex = i;
        }
    }

    printResult(max, maxIndex);
    printResult(min, minIndex);

    free(arr);
    return 0;
}
