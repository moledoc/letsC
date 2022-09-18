#include <stdio.h>

#define INDENT '\t'

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
// #define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
// #define ANSI_COLOR_MAGENTA "\x1b[35m"
// #define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define STR_COLOR ANSI_COLOR_RED
#define OBJ_COLOR ANSI_COLOR_GREEN
#define VAL_COLOR ANSI_COLOR_BLUE

// instead of including string.h, implement necessary funcs myself
int strcmp(const char *s1, const char *s2);
size_t strlen(const char *c);

// other (help) functions
void newline(const int level);
int allow_color(int argc, char **argv);

size_t strlen(const char *c)
{
	size_t len = 0;
	while ( *c++ != '\0' ){
		++len;
	}
	return len;
}

int strcmp(const char *s1, const char *s2)
{
	int s1_len = strlen(s1);
	if (s1_len != strlen(s2)){
		return 0;
	}
	for (int i = 0; i < s1_len; ++i){
		if (*s1++ != *s2++){
			return 0;
		}
	}
	return 1;
}

void newline(const int level)
{
	putchar('\n');
	for (int i=0; i < level; ++i ){
		putchar(INDENT);
	}

}

int allow_color(int argc, char **argv)
{
    for( int i = 1; i < argc; ++i ) {
        if (strcmp(argv[i],"--color") ){
			return 1;
		}
    }
	return 0;
}

int main(int argc, char **argv)
{
	int with_color = allow_color(argc,argv);
	int c;
	int level = 0;
	int in_quote = 0;
	char in_quote_prev;
	while ((c=getchar()) != EOF){
		if (!in_quote && (c == ' ' || c == '\t' || c == '\n' )){
			continue;
		}
		if ( !in_quote && (c == '{' || c == '[')){
			if (with_color) printf(OBJ_COLOR);
			putchar(c);
			newline(++level);
			if (with_color) printf(VAL_COLOR);
			continue;
		}
		if (!in_quote && ( c == '}' || c == ']')){
			newline(--level);
			if (with_color) printf(OBJ_COLOR);
			putchar(c);
			if (with_color) printf(VAL_COLOR);
			continue;
		}
		if (!in_quote && ( c == ',' )){
			if (with_color) printf(OBJ_COLOR);
			putchar(c);
			newline(level);
			if (with_color) printf(VAL_COLOR);
			continue;
		}
		if ( !in_quote && (c == ':' )){
			if (with_color) printf(OBJ_COLOR);
			putchar(c);
			putchar(' ');
			if (with_color) printf(VAL_COLOR);
			continue;
		}
		if (c == '"' && in_quote){
			in_quote=(in_quote + 1)%2;
			putchar(c);
			if (with_color && in_quote_prev != '\\') printf(VAL_COLOR);
			continue;
		}
		if ( c == '"' && !in_quote){
			in_quote=(in_quote + 1)%2;
			if (with_color) printf(STR_COLOR);
			putchar(c);
			continue;
		}
		if ( in_quote ){
			in_quote_prev = c;
		}
		putchar(c);
	}
	if (with_color) printf(ANSI_COLOR_RESET);
	newline(level);
	return 0;
}

