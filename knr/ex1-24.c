#include <stdio.h>

#define OFFSET 3
#define OPENED_SIZE 100*OFFSET

//Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
//unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
//double, escape sequences, and comments. (This program is hard if you do it in full
//generality.)

int main(int argc, char **argv[])
{
	int c, prev;

	int paren[3];
	int bracket[3];
	int brace[3];
	int quote[3];
	int double_quote[3];
	char escapeables[11];
	escapeables[0] = 'a';
	escapeables[1] = 'b';
	escapeables[2] = 't';
	escapeables[3] = 'n';
	escapeables[4] = 'v';
	escapeables[5] = 'f';
	escapeables[6] = 'r';
	escapeables[7] = '\\';
	escapeables[8] = '"';
	escapeables[9] = '\'';
	escapeables[10] = '?';

	int row, col;
	row = col = 1;

	int in_comment = 0;

	int last_opened_idx =-1*OFFSET;
	char opened[OPENED_SIZE];
	while ((c=getchar()) != EOF) {
		if ( c == '\n' ){
			in_comment = 0;
			col = 0;
			++row;
		} else if (c == '/' && c == prev){
			in_comment = 1;
		} else if (prev == '*' && c == '/' ){
			in_comment = 0;
		} else if (prev == '/' && c == '*' ){
			in_comment = 1;
		} else if (prev == '\\'){
			int is_escapeable = 0;
			for (int i = 0; i< sizeof escapeables; ++i){
				if (escapeables[i] == c){
					is_escapeable = 1;
				}
			}
			if (!is_escapeable){
				printf("Incorrect escape sequence at r:%d c:%d\n",row,col);
			}
		} else if (c == '\'' && quote[0] && prev != '\\') {
			quote[0] = 0;
		} else if (c == '\'' && !quote[0]) {
			quote[0] = 1;
			quote[1] = row;
			quote[2] = col;
		} else if (c == '\"' && double_quote[0] && prev != '\\') {
			double_quote[0] = 0;
		} else if (c == '\"' && !double_quote[0]) {
			double_quote[0] = 1;
			double_quote[1] = row;
			double_quote[2] = col;
		} else if ((c == ')' || c == ']' || c == '}') && last_opened_idx < 0 ) {
			// TODO: what to do when this happens
			printf("Nothing to close with '%c' at r:%d c:%d\n",c,row,col);
		} else if ((c == ')' || c == ']' || c == '}') && last_opened_idx >= 0 ) {
			if ((c - opened[last_opened_idx]) > 2){ // NOTE: biggest diff between ascii chars is 2
				printf("Trying to close '%c' at r:%d c:%d with '%c' at r:%d c:%d\n",
					opened[last_opened_idx],
					opened[last_opened_idx+1],
					opened[last_opened_idx+2],
					c,row,col);
			} else {
				last_opened_idx = last_opened_idx - OFFSET;
			}
		} else if (c == '(' || c == '[' || c == '{') {
			last_opened_idx = last_opened_idx+OFFSET;
			if (last_opened_idx > OPENED_SIZE){
				printf("Too many parenthesis open, close some or increase the buffer size at r:%d c:%d\n",row,col);
				break;
			}
			opened[last_opened_idx] = c;
			opened[last_opened_idx+1] = row;
			opened[last_opened_idx+2] = col;
		}
		++col;
		prev = c;
	}
	if ( quote[0] ){
		printf("Unclosed quote at r:%d c:%d\n",quote[1],quote[2]);
	}
	if ( double_quote[0] ){
		printf("Unclosed double quote at r:%d c:%d\n",double_quote[1],double_quote[2]);
	}
	if (last_opened_idx >= 0) {
		for (int i = last_opened_idx; i> -OFFSET; i=i-OFFSET){
			printf("Did not close '%c' at r:%d c:%d\n",
				opened[i],
				opened[i+1],
				opened[i+2]);
		}
	}
	return 0;
}

