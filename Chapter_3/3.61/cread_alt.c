#include <stdio.h>

long cread_alt(long *xp)
{
    return (!xp ? 0 : *xp);
}

int main()
{
    long x, result;

    scanf("%ld", &x);
    result = cread_alt(&x);
    printf("%ld\n", result);

    return 0;
}