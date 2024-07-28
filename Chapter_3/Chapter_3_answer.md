# Chapter3 answer

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




## References

[CSAPP 第三章家庭作业 - 付玬熙 - 博客园](https://www.cnblogs.com/fudanxi/p/17094591.html)
