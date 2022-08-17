#include <stdio.h>

#define MAXLINE 100

//Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.


int getline_self(char line[], int limit);

int main(void)
{
	int len;				// current line length
	char line[MAXLINE];		// current input line
	int c;
	while (( len = getline_self(line,MAXLINE)) > 0)
		if ( len >= 80 )
			printf("%s",line);
	return 0;
}

int getline_self(char s[], int lim)
{
	int c, i;
	for ( i=0; i< lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

