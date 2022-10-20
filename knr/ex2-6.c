#include <stdio.h>

// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.

unsigned setbits(unsigned x, int p, int n, unsigned y);

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x | ((y & ~(~0 << n)) << (p+1-n));
}

int main(void)
{
	unsigned x = 0b1000;
	unsigned y = 0b0101;
	int p = 2;
	int n = 3;
	printf("%d\n", setbits(x,p,n,y));
	return 0;
}