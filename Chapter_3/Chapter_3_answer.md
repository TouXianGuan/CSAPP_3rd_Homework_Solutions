# Chapter3 Answer

## 3.58

```
long decode2(long x, long y, long z)
{
	long a = y - z;
	long b = x * a;
	return (((a << 63) >> 63) ^ b;
}
```

## 3.59

Let $ m = x\_l \\cdot y\_l = 2^64 \\cdot m\_h + m\_l $, $ n = x\_l \\cdot y\_h + x\_h \\cdot y\_l = 2^64 \\cdot n\_h + n\_l $, then $ p\_l = m\_l, p\_h = m\_h + n\_l.

## 3.60

### A

%rdi, %rsi, %rax, %rdx

### B

0, 1

### C

mask != 0

### D

mask = mask << n

### E

result |= x & mask

### F

```
long loop(long x, int n)
{
	long result = 0;
	long mask;
	for (mask = 1; mask != 0; mask = mask << n) {
		result |= x & mask;
	}
	return result;
}
```

## 3.61

```
long cread_alt(long *xp) {
	return (!xp ? 0 : *xp);
}
```

## 3.62

```
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
```

## 3.63

```
long switch_prob(long x, long n) {
	long result = x;
	switch(n) {
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
```

## 3.64

### A

` &A[i][j][k] = x_A + L(S * T * i + T * j + k)`

### B

R = 7, S = 5, T = 13.

## 3.65

### A

%rdx

### B

%rax

### C

15

## 3.66

NR(x) (3 * (x))

NC(X) (4 * (x) + 1)

## 3.67

### A

- M[%rsp+80] z
- M[%rsp+72] x
- M[%rsp+64] y
- M[%rsp+24] z
- M[%rsp+16] &z (%rsp+24)
- M[%rsp+8] y
- M[%rsp+0] x

### B

&s in %rdi; x, y, &z in the stack frame.

### C

Use movq instruction to load s.a[0], s.a[1], s.p to registers.

### D

Use movq instruction to store r.u[0], r.u[1], r.q from registers.

### E

r has been stored in %rsp+64. So loading r.u[0] from M[%rsp+64], loading r.u[1] form M[%rsp+72], loading r.q form M[%rsp+80].

### F

The first way is using registers. When the size of passed argument is smaller than 8 bits (include 8 bits), we can use registers. When we pass a structure or other heterigenous data structures, we need use stack. it is the second way. Returned values is analogous.l;

## 3.68

A is 5; B is 9.

## 3.69

### A

7

### B

```
typedef struct {
	int idx;
	int x[4];
} a_struct;
```

## 3.70

### A

0; 8; 0; 8.

### B

16

### C

up->e2.x = *((up->e2.next)->e1.p) - up->e2.next->e1.y

## 3.71

```
#include <stdio.h>

#define GOOD_ECHO_SIZE 10

int good_echo()
{
    char a[GOOD_ECHO_SIZE];

    while (1)
    {
        char *p = fgets(a, GOOD_ECHO_SIZE, stdin);
        if (!p)
        {
            return ferror(stdin);
        }
        printf("%s", p);
    }
}

int main()
{
    printf("%d\n", good_echo());

    return 0;
}
```

## 3.72

### A

s2 = s1 - ((8 * n + 30) - (8 * n + 30) mod 16))

### B

p = (s2 + 15) - ((s2 + 15) mod 16)

### C

e1_min = 1;

e1_max = 24

### D

The adress of p is a multiple of 16. The adress of s2 is s1 subtract a multiple of 16 and it can contain p;

## 3.73

```
range_t find_range(float x)
{
    asm(
        "vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm0, %xmm1\n\t"
        "ja .LA\n\t"
        "je .LB\n\t"
        "jb .LC\n\t"
        "jmp .LD\n\t"
        ".LA:\n\t"
        "movl $0, %eax\n\t"
        "jmp .LE\n\t"
        ".LB:\n\t"
        "movl $1, %eax\n\t"
        "jmp .LE\n\t"
        ".LC:\n\t"
        "movl $2, %eax\n\t"
        "jmp .LE\n\t"
        ".LD:\n\t"
        "movl $3, %eax\n\t"
        "jmp .LE\n\t"
        ".LE:\n\t");
}
```

## 3.74

```
range_t find_range(float x)
{
    asm(
        "movl $3, %eax\n\t"
        "vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm0, %xmm1\n\t"
        "movl $0, %edx\n\t"
        "cmova %edx, %eax\n\t"
        "movl $1, %edx\n\t"
        "cmove %edx, %eax\n\t"
        "movl $2, %edx\n\t"
        "cmovb %edx, %eax\n\t");
}
```

## 3.75

### A

real in %xmm0, imag in %xmm1.

### B

return %xmm0 and %xmm1.


## References

[CSAPP 第三章家庭作业 - 付玬熙 - 博客园](https://www.cnblogs.com/fudanxi/p/17094591.html)
