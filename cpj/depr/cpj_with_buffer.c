#include <stdio.h>

#define BUF_SIZE 16
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

// instead of including string.h, implement my own strcat and strlen
// because I want to and need to handle buf overflow
char *strcat(char *dest, const char *source);
size_t strlen(const char *c);
int strcmp(const char *s1, const char *s2);
void charcat(char *dest, const char source);

// other (help) functions
void newline(char *dest, const int level);
int dont_overflow(char *dest, int len, int fit);
int allow_color(int argc, char **argv);
void clear(char *buf);

char *strcat(char *dest, const char *c)
{
	int len = strlen(dest);
	len = dont_overflow(dest,len,strlen(c));
	char *ptr = dest + len;
	while (*c != '\0'){
		*ptr++ = *c++;
	}
	*ptr='\0';
}

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

void charcat(char *dest, const char c)
{
	int len = strlen(dest);
	len = dont_overflow(dest,len,1);
	char *ptr = dest + len;
	*ptr++ = c;
	*ptr='\0';
}

int dont_overflow(char *dest, int len, int fit)
{
	if (BUF_SIZE > len+fit){
		return len;
	}
	printf(dest);
	clear(dest);
	return 0;
}

void newline(char *dest, const int level)
{
	int len = strlen(dest);
	len = dont_overflow(dest,len,level+1);
	char *ptr = dest + len;
	*ptr++ = '\n';
	for (int i=0; i < level; ++i ){
		*ptr++ = INDENT;
	}
	*ptr='\0';

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

void clear(char *buf)
{
	for(size_t i = 0; i < sizeof buf; ++i){
	  buf[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int with_color = allow_color(argc,argv);
	int c;
	int level = 0;
	char buf[BUF_SIZE];
	int in_quote = 0;
	char in_quote_prev;
	while ((c=getchar()) != EOF){
		if (!in_quote && (c == ' ' || c == '\t' || c == '\n' )){
			continue;
		}
		if ( !in_quote && (c == '{' || c == '[')){
			if (with_color) strcat(buf,OBJ_COLOR);
			charcat(buf,c);
			newline(buf,++level);
			if (with_color) strcat(buf,VAL_COLOR);
			continue;
		}
		if (!in_quote && ( c == '}' || c == ']')){
			newline(buf,--level);
			if (with_color) strcat(buf,OBJ_COLOR);
			charcat(buf,c);
			if (with_color) strcat(buf,VAL_COLOR);
			continue;
		}
		if (!in_quote && ( c == ',' )){
			if (with_color) strcat(buf,OBJ_COLOR);
			charcat(buf,c);
			newline(buf,level);
			if (with_color) strcat(buf,VAL_COLOR);
			continue;
		}
		if ( !in_quote && (c == ':' )){
			if (with_color) strcat(buf,OBJ_COLOR);
			charcat(buf,c);
			charcat(buf,' ');
			if (with_color) strcat(buf,VAL_COLOR);
			continue;
		}
		if (c == '"' && in_quote){
			in_quote=(in_quote + 1)%2;
			charcat(buf,c);
			if (with_color && in_quote_prev != '\\') strcat(buf,VAL_COLOR);
			continue;
		}
		if ( c == '"' && !in_quote){
			in_quote=(in_quote + 1)%2;
			if (with_color) strcat(buf,STR_COLOR);
			charcat(buf,c);
			continue;
		}
		if ( in_quote ){
			in_quote_prev = c;
		}
		charcat(buf,c);
	}
	if (with_color) strcat(buf,ANSI_COLOR_RESET);
	newline(buf,level);
	printf(buf);
	return 0;
}
