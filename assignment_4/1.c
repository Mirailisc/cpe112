// Phubordin Poolnai 66070501040

#include <stdio.h>

void covertNumberToBase(long long int n, int base)
{
    if (base < 2 || base > 36)
    {
        printf("invalid\n");
        return;
    }

    char out[65];
    int len = 0;

    while (n > 0)
    {
        int digit = n % base;
        char new_digit;

        if (digit >= 0 && digit <= 9)
        {
            new_digit = (char)(digit + '0');
        }
        else
        {
            new_digit = (char)(digit - 10 + 'A');
        }

        n /= base;
        out[len] = new_digit;
        len++;
    }

    if (len == 0)
    {
        printf("0\n");
        return;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", out[i]);
    }
    printf("\n");
}

int main()
{
    long long int n;
    int base;

    scanf("%lld %d", &n, &base);

    covertNumberToBase(n, base);

    return 0;
}
