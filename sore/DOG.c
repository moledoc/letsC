#include <stdio.h>

// README DOG is like dog, but it parses escaped symbols.

char escape(char c, FILE *f);

char escape(char c, FILE *f)
{
	if ( c  == '0' || c == '1') {
		char prev;
		char oct = 0;
		for ( int i = 0; i<3 || c == EOF; ++i ){
			if ( c >= '0' && c <= '9'){
				if ( i ) {
					oct *= 8;
				}
				oct += c - '0';
				prev = c;
				c=getc(f);
			} else {
				putchar(oct);
				if (c == '\\'){
					return prev;
				}
				putchar(c);
				return c;
			}
		}
		putchar(oct);
		putchar(c);
	} else if ( c == 'x' ){
		c=getc(f);
		char prev;
		char hex = 0;
		for ( int i = 0; i<2 || c == EOF; ++i ){
			if ( c >= '0' && c <= '9'){
				if ( i ) {
					hex *= 16;
				}
				hex += c - '0';
				prev = c;
				c=getc(f);
			} else if ( c >= 'a' && c <= 'f' ) {
				if ( i ) {
					hex *= 16;
				}
				hex += c - 'a' + 10;
				prev = c;
				c=getc(f);
			} else if ( c >= 'A' && c <= 'F' ){
				if ( i ) {
					hex *= 16;
				}
				hex += c - 'A' + 10;
				prev = c;
				c=getc(f);
			} else {
				putchar(hex);
				if (c == '\\'){
					return prev;
				}
				putchar(c);
				return c;
			}
		}
		putchar(hex);
		putchar(c);
	} else {
		switch (c) {
		case 'a':
			putchar('\a'); break;
		case 'b':
			putchar('\b'); break;
		case 't':
			putchar('\t'); break;
		case 'n':
			putchar('\n'); break;
		case 'v':
			putchar('\v'); break;
		case 'f':
			putchar('\f'); break;
		case 'r':
			putchar('\r'); break;
		case '\\':
			putchar('\\'); break;
		case '\'':
			putchar('\''); break;
		case '\"':
			putchar('\"'); break;
		default:
			putchar('\\');
			putchar(c);
		}
	}
	return c;
}

int main(int argc, char **argv)
{
	if (argc == 1){
		return 0;
	}
	for (int i =1; i<argc; ++i){
		FILE *f;
		f = fopen(argv[i],"r");
		char c;
		while ((c=getc(f)) != EOF){
			if (i > 1){
				putchar(' ');
			}
			while ( c != EOF){
				if ( c == '\\' ){
					c=getc(f);
					if ((c = escape(c,f)) == EOF){
						putchar('\n');
						return 0;
					}
				} else {
					putchar(c);
				}
				c=getc(f);
			}
		}
		fclose(f);
	}
    return 0;
}
