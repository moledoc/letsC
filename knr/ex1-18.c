#include <stdio.h>

//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
//and to delete entirely blank lines.

#define MAXLINE 1000

int gl(char line[], int limit);

int main(void)
{
	int len;
	char line[MAXLINE];
	while ((len = gl(line,MAXLINE)) > 0) {
		if (len == 1)
			continue;
		int i;
		for (i=len-1;i>-1;--i) {
			if (line[i] == '\n' || line[i] == '\0')
				continue;
			if (line[i] != ' ' && line[i] != '\t'){
				break;
			}
			line[i] = '\0';
		}
		printf("%s",line);
	}
	return 0;
}

int gl(char s[], int lim)
{
	int c,i;
	for (i = 0; i< lim -1 && (c=getchar()) !=EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

// test test   			 
