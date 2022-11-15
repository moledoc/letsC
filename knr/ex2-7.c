#include <stdio.h>

// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

unsigned invert(unsigned x, int p, int n);

unsigned invert(unsigned x, int p, int n)
{
	return x ^ ~(~0 << n) << (p+1-n);
}

int main(void)
{
	unsigned x = 0b1101;
	int p = 3;
	int n = 3;
	printf("%d\n", invert(x,p,n));
	return 0;
}