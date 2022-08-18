#include <stdio.h>

//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
//more blanks by a single blank.
// ie make double blanks single blank

int main(void)
{
	int isBlank = 0;
	int c;
	while ((c=getchar()) != EOF)
	{
		if (c == ' ' && isBlank)
			continue;
		if (c == ' ')
			isBlank = 1;
		if (c != ' ' && isBlank)
			isBlank = 0;
		putchar(c);
	}
	return 0;
}
