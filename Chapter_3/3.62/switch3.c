#include <stdio.h>
typedef enum
{
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} mode_t;

long switch3(long *p1, long *p2, mode_t action)
{
    long result = 0;
    switch (action)
    {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;
    case MODE_B:
        result = *p1 + *p2;
        *p1 = result;
        break;
    case MODE_C:
        *p1 = 59;
        result = *p2;
        break;
    case MODE_D:
        result = 27;
        *p1 = *p2;
        break;
    case MODE_E:
        result = 27;
        break;
    default:
        result = 12;
        break;
    }
    return result;
}

int main()
{
    mode_t action;
    long p1, p2;
    int act;

    if (scanf("%ld %ld %d", &p1, &p2, &act) != 3)
    {
        fprintf(stderr, "Error: Invalid input\n");
        return 1;
    }
    action = act;
    printf("%ld", switch3(&p1, &p2, action));

    return 0;
}
