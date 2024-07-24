# 3.58 answer

```
long decode2(long x, long y, long z)
{
	long a = y - z;
	long b = x * a;
	return (((a << 63) >> 63) ^ b;
}
```