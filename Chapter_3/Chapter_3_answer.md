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

