#include <stdio.h>

//Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
//handle quoted strings and character constants properly. C comments don't nest.

// two cases: line comments and block comments

void line_comment();
void block_comment();

int main(void)
{
	int c;
	int is_slash = 0;
	while ((c=getchar()) != EOF){
		if ( is_slash == 0 && c == '/' ){
			is_slash = 1;
			continue;
		}
		if (is_slash && c == '/' ){
			line_comment();
			is_slash = 0;
			continue;
		}
		if (is_slash && c == '*' ){
			block_comment();
			is_slash = 0;
			continue;
		}
		if (is_slash && c != '/' && c != '*' ){
			putchar('/');
			is_slash = 0;
		}
		putchar(c);
	}
	return 0;
}

void line_comment()
{
	int c;
	while ((c=getchar()) != EOF && c != '\n')
		;
}

/*
test data: block comment
*/void block_comment()
{
	int c;
	int is_comment = 1;
	int is_star = 0;
	while ((c=getchar()) != EOF && is_comment){
		if (is_star && c == '/')
			is_comment = 1;
		if ( c == '*' )
			is_star = 1;
	}
}

// test data: one line comment
/*
test data: block comment
*/
/*test data: block comment*/

