#include <stdio.h>

long decode2(long x, long y, long z)
{
    long a = y - z;
    long b = x * a;
    return ((a << 63) >> 63) ^ b;
}

int main()
{
    long x, y, z;

    scanf("%ld%ld%ld", &x, &y, &z);
    printf("%ld\n", decode2(x, y, z));

    return 0;
}