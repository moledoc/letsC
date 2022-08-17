#include <stdio.h>

//Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to
//write a program that reverses its input a line at a time.

#define MAXLINE 1000

int gl(char line[], int limit);
void reverse(char s[]);

int main(void)
{
	int len;
	char line[MAXLINE];
	while ((len = gl(line,MAXLINE)) > 0) {
		reverse(line);
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

void reverse(char s[])
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	int until = i/2;
	if (i % 2 == 0)
		--until;
	for (int j = i-1; j>until; --j){
		int buf = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = buf;
	}
}

