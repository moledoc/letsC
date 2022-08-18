#include <stdio.h>

//Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
//the last non-blank character that occurs before the n -th column of input. Make sure your
//program does something intelligent with very long lines, and if there are no blanks or tabs
//before the specified column.

#define COL 20

int line(char l[],int limit);

int main(void)
{
	int len;
	char l[COL];
	while ((len = line(l,COL)) > 0){
		if (len == COL-1){
			int is_blank = 1;
			int i = len - 1;
			while (is_blank){
				if (l[i] != ' ' && l[i] != '\t'){
					is_blank = 0;
					l[i+1] = '\n';
					continue;
				}
				l[i] = '\0';
				--i;
			}
		}
		printf("%s",l);
	}
	return 0;
}

int line(char l[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		l[i] = c;
	if ( c == '\n' ){
		l[i] = c;
		++i;
	}
	l[i] = '\0';
	return i;
}
