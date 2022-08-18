#include <stdio.h>

//Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t , each
//backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way

//1-10-2 is reverse of 1-10.

int main(void)
{
	int c;
	int is_backspaced = 0;
	while ((c=getchar()) != EOF)	{
		if (c == '\\') {
			is_backspaced = 1;
			continue;
		}
		if ( is_backspaced && c == 'b'){
			putchar('\b');
			continue;
		}
		if ( is_backspaced && c == 't'){
			putchar('\t');
			continue;
		}
		putchar(c);
		is_backspaced = 0;
	}
	return 0;
}
