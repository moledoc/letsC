#include <stdio.h>

//Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
//unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
//double, escape sequences, and comments. (This program is hard if you do it in full
//generality.)

/* TODO:
* ~single quotes~
* ~double quotes~
* parenthesis
* brackets
* braces
* ~line comments~
* ~block comment~
* ~escape sequence~
*/

void quotes(int b[], const char c, const char p);
void init(int b[]);

void quotes(int b[], const char c, const char p)
{
	
}


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
	while ((c=getchar()) != EOF) {
		if ( c == '\n' ){
			in_comment = 0;
			col = 0;
			++row;
		}
		////
		if (c == '/' && c == prev){
			in_comment = 1;
		}
		////
		if (prev == '*' && c == '/' ){
			in_comment = 0;
		}
		if (prev == '/' && c == '*' ){
			in_comment = 1;
		}
		////
		if (prev == '\\'){
			int is_escapeable = 0;
			for (int i = 0; i< sizeof escapeables; ++i){
				if (escapeables[i] == c){
					is_escapeable = 1;
				}
			}
			if (!is_escapeable){
				printf("Incorrect escape sequence at r:%d c:%d\n",row,col);
			}
		}
		////
		if (!in_comment && c == '\'' && quote[0] && prev != '\\') {
			quote[0] = 0;
		}
		if (!in_comment && c == '\'' && !quote[0]) {
			quote[0] = 1;
			quote[1] = row;
			quote[2] = col;
		}
		////
		if (!in_comment && c == '\"' && double_quote[0] && prev != '\\') {
			double_quote[0] = 0;
		}
		if (!in_comment && c == '\"' && !double_quote[0]) {
			double_quote[0] = 1;
			double_quote[1] = row;
			double_quote[2] = col;
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
	return 0;
}

// int main(int argc, char **argv[])
// {
	// int c, prev;
	// 
	// int paren[3];
	// int bracket[3];
	// int brace[3];
	// int quote[3];
	// int double_quote[3];
// 
	// int row, col;
	// row = col = 1;
// 
	// int in_line_comment = 0;
	// int in_block_comment = 0;
	// while ((c=getchar()) != EOF) {
		// if ( c == '\n' ){
			// in_line_comment = 0;
			// col = 0;
			// ++row;
		// }
		// ////
		// if (!(in_line_comment || in_block_comment) && c == '/' && c == prev){
			// in_line_comment = 1;
		// }
		// ////
		// if (!(in_line_comment || in_block_comment) && prev == '*' && c == '/' ){
			// in_block_comment = 0;
		// }
		// if (!(in_line_comment || in_block_comment) && prev == '/' && c == '*' ){
			// in_block_comment = 1;
// 
// 
		// }
		// ////
		// if (!(in_line_comment || in_block_comment) && c == '\'' && quote[0] && prev != '\\') {
			// quote[0] = 0;
		// }
		// if (!(in_line_comment || in_block_comment) && c == '\'' && !quote[0]) {
			// quote[0] = 1;
			// quote[1] = row;
			// quote[2] = col;
		// }
		// ////
		// if (!(in_line_comment || in_block_comment) && c == '\"' && double_quote[0] && prev != '\\') {
			// double_quote[0] = 0;
		// }
		// if (!(in_line_comment || in_block_comment) && c == '\"' && !double_quote[0]) {
			// double_quote[0] = 1;
			// double_quote[1] = row;
			// double_quote[2] = col;
		// }
		// ++col;
		// prev = c;
	// }
	// if ( quote[0] ){
		// printf("Unclosed quote at r:%d c:%d\n",quote[1],quote[2]);
	// }
	// if ( double_quote[0] ){
		// printf("Unclosed double quote at r:%d c:%d\n",double_quote[1],double_quote[2]);
	// }
	// return 0;
// }
// 
