#include <stdio.h>

//Exercise 1-20. Write a program `detab` that replaces tabs in the input with the proper number
//of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
//Should n be a variable or a symbolic parameter?

#define TABSTOP 4

int main(void)
{
	int c;
	while ((c=getchar()) != EOF){
		if (c=='\t'){
			for (int i=0;i<TABSTOP;++i)
				putchar(' ');
			continue;
		}
		putchar(c);
	}
	return 0;
}

// good example:
// ```sh
// cat ex1-20.c | ./ex1-10 | ./ex1-20
// ```
// (ex1-10 changes tabs to \t)
