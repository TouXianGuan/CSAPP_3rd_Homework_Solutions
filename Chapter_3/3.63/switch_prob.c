#include <stdio.h>

long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 0:
    case 2:
        result = 8 * x;
        break;
    case 3:
        result = n >> 3;
        break;
    case 4:
        x = 15 * x;
    case 5:
        x = x * x;
    case 1:
    default:
        result = x + 59;
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