// longest line program from the book
#include <stdio.h>

#define MAXLINE 10 /* maximum input line length */

int getline_self(char line[], int maxline);
void copy(char to[], char from[]);

// main from the book
//int main(void)
//{
//	int len;                // current line length
//	int max;                // maximum length seen so far
//	char line[MAXLINE];     // current input line
//	char longest[MAXLINE];  // longest line saved
//	max = 0;
//	while (( len = getline_self(line,MAXLINE)) > 0)
//		if ( len > max ){
//			max = len;
//			copy(longest,line);
//		}
//	if ( max > 0 )
//		printf("%s\n",longest);
//	return 0;
//}

//Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
//the length of arbitrary long input lines, and as much as possible of the text.

int main(void)
{
	int len;				// current line length
	int max = 0;			// maximum length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];		// current input line
	int c;
	while (( len = getline_self(line,MAXLINE)) > 0){
		if (line[len - 1] != '\n'){
			while (( c = getchar()) != EOF && c != '\n')
				++len;
		}
		if ( len > max ){
			max = len;
			copy(longest,line);
		}
	}
	if ( max > 0 )
		printf("Longest line length: %d\nLine: %s....\n",max,longest);
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

void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

