// Phubordin Poolnai 66070501040

#include <stdio.h>

int totalMoves = 0;

void moveDisks(int n, char source, char destination, char auxiliary)
{
    totalMoves++;

    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    moveDisks(n - 1, source, auxiliary, destination);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    moveDisks(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    scanf("%d", &n);

    moveDisks(n, 'A', 'C', 'B');
    printf("Total moves: %d\n", totalMoves);

    return 0;
}
