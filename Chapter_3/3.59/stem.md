# 3.59 stem

The following code computes the 128-bit product of two 64-bit signed values *x* and *y* and stores the result in memory.

```
1	typedef __int128 int128_t;
2
3	void store_prod(int128_t *dest, int64_t x, int64_t y){
4		*dest = x * (int128_t) y;
5	}
```

Gcc generates the following assembly code implementing the computation：

```
1   store_prod:
2     movq      %rdx, %rdx
3     cqto
4     movq      %rsi, %rcx
5     sarq      $63, %rcx
6     imulq     %rax, %rcx
7     imulq     %rsi, %rdx
8     addq      %rdx, %rcx
9     mulq      %rsi
10    addq      %rcx, %rdx
11    movq      %rax, (%rdi)
12    movq      %rdx, 8(%rdi)
13    ret
```

This code uses three multiplications for the multiprecision arithmetic required to implement 128-bit arithmetic on a 64-bit machine. Describe the algorithm used to compute the product, and annotate the assembly code to show how it realizes your algorithm. *Hint*: When extending arguments of x and y to 128 bits, they can be rewritten as $ x = 2^64 \\cdot x\_h + x\_l $ and $ y = 2^64 \\cdot y\_h + y\_l $, where x\_h. x\_l, y\_h, and y\_l are 64-bit values. Similarly, the 128-bit product can be written as $ p = 2^64 \\cdot p\_h + p\_l $, where p\_h and p\_l are 64-bit values. Show how the code computes the values of p\_h and p\_l in terms of x\_h, x\_l, y\_h, and y\_l.