#include <stdio.h>

long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result = 8 * x;
        break;
    case 63:
        result = n >> 3;
        break;
    case 64:
        x = 15 * x;
    case 65:
        x = x * x;
    case 61:
    default:
        result = x + 75;
        break;
    }
    return result;
}

int main()
{
    long x, n;

    if (scanf("%ld%ld", &x, &n) != 2)
    {
        fprintf(stderr, "Error: Invalid input\n");
        return 1;
    }
    printf("%ld\n", switch_prob(x, n));
}