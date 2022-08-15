#include <stdio.h>
//Exercise 1-8. Write a program to count blanks, tabs, and newlines.

int main(void)
{
	int nb , nt , nn, c;
	nb = nt = nn = 0;
	while ( (c=getchar()) != EOF)
	{
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nn;
	}
	printf("%8s: %d\n%8s: %d\n%8s: %d\n","Blanks",nb,"Tabs",nt,"Newlines", nn);
	return 0;
}
