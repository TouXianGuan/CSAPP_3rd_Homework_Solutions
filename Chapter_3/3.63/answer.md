# 3.63 answer

```
long switch_prob(long x, long n) {
	long result = x;
	switch(n) {
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
```