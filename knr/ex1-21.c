#include <stdio.h>

//Exercise 1-21. Write a program `entab` that replaces strings of blanks by the minimum
//number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab .
//When either a tab or a single blank would suffice to reach a tab stop, which should be given

#define TABSTOP 4

int main(void)
{
	int c;
	int blank_counter = 0;
	while ((c=getchar()) != EOF){
		if ( c != ' ') {
			for (int i = 0; i< blank_counter; ++i)
				putchar(' ');
			putchar(c);
			blank_counter = 0;
			continue;
		}
		if (c == ' ')
			++blank_counter;
		if (blank_counter == TABSTOP){
			putchar('\t');
			blank_counter = 0;
		}
	}
	return 0;
}


// good example is when combining the follwing programs with ex1-21
// ex1-20 changes tabs to spaces
// ex1-10 shows tabs explicitly
// ```sh
//       cat ../ex1-21.c | ./ex1-21 | ./ex1-10
// ```
// lenghtier transformation (play with parts of it)
// ```sh
// cat ../ex1-21.c | ./ex1-21 | ./ex1-10 | ./ex1-10-2 | ./ex1-20 | ./ex1-10 | ./ex1-10-2 | ./ex1-21 | ./ex1-10
// ```
