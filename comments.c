#include <stdio.h>

//This program is inspired by ex1-23 and mainly uses same code.
//Instead of removing the comments, it extracts them.

void line_comment(char b[2]);
void block_comment(char b[2]);
void quoted(char b[2]);
void double_quoted(char b[2]);

void line_comment(char buf[2])
{
	while ((buf[1]=getchar()) != EOF && buf[1] != '\n'){
		putchar(buf[1]);
	}
	if (buf[1] == '\n'){
		putchar('\n');
	}
	buf[0] = '\n';
	buf[1] = getchar();
}

void block_comment(char buf[2])
{
	buf[0] = getchar();
	while ((buf[1]=getchar()) != EOF ){
		if (buf[0] == '*' && buf[1] == '/'){
			break;
		}
		putchar(buf[0]);
		buf[0] = buf[1];
	}
	buf[0] = getchar();
	buf[1] = getchar();
	putchar('\n');
}

void double_quoted(char buf[2])
{
	buf[0] = buf[1];
	while ((buf[1] = getchar()) != EOF){
		if (buf[1] == '"' && buf[0] != '\\'){
			break;
		}
		buf[0] = buf[1];
	}
	buf[0] = buf[1];
	buf[1] = getchar();
}

void quoted(char buf[2])
{
	while ((buf[1] = getchar()) != '\''){}
	buf[0] = getchar();
	if (buf[0] == '\''){
		buf[0] = getchar();
	}
}

int main(void)
{
	char s[21] = "\"testing /; //; /* */"; // TEST: double quotes
	int test = 4/2;
	char buf[2];
	buf[0] = getchar();
	while ((buf[1]=getchar()) != EOF){
		if (buf[1] == '\''){
			quoted(buf);
		}
		if (buf[1] == '\"'){
			double_quoted(buf);
		}
		if (buf[0] == '/' && buf[1] == '/'){ // TEST: inline one-line comment
			line_comment(buf);
		}/*TEST:
		inline 
		block comment
		FIXME:*/	if (buf[0] == '/' && buf[1] == '*'){
			block_comment(buf);
		}
		buf[0] = buf[1];
	}
	return 0;
}



// TEST: line comment
/* TEST: one line block comment */
/*
TEST: multi line
TEST: block comment
*/
// TEST: testing if division works in line comment: 4/2
/*TEST: testing if division works in block comment: 4/2*/
/* TEST: testing if division works in block comment: 4/2 */
