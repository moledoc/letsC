#include <stdio.h>

//Exercise 1-12. Write a program that prints its input one word per line.

int main(void){
	int c, blank;
	blank = 0;
	while ((c=getchar()) != EOF) {
		if ( c == ' ' || c == '\t' ){
			putchar('\n');
			blank = 1;
			continue;
		}
		if ( c == '\n' && blank) 
			continue;
		putchar(c);
	}
	putchar('\n');
	return 0;
}
