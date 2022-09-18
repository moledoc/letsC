#include <stdio.h>

// README - say is basic implementation of `echo`

char *escape(char *cs);

char *escape(char *cs)
{
	if ( *cs  == '0' || *cs == '1') {
		char oct = 0;
		for ( int i = 0; i<3 || *cs == '\0'; ++i ){
			if ( *cs >= '0' && *cs <= '9'){
				if ( i ) {
					oct *= 8;
				}
				oct += *cs - '0';
				++cs;
			} else {
				putchar(oct);
				if (*cs == '\\'){
					--cs;
					return cs;
				}
				putchar(*cs);
				return cs;
			}
		}
		putchar(oct);
		putchar(*cs);
	} else if ( *cs == 'x' ){
		++cs;
		char hex = 0;
		for ( int i = 0; i<2 || *cs == '\0'; ++i ){
			if ( *cs >= '0' && *cs <= '9'){
				if ( i ) {
					hex *= 16;
				}
				hex += *cs - '0';
				++cs;
			} else if ( *cs >= 'a' && *cs <= 'f' ) {
				if ( i ) {
					hex *= 16;
				}
				hex += *cs - 'a' + 10;
				++cs;
			} else if ( *cs >= 'A' && *cs <= 'F' ){
				if ( i ) {
					hex *= 16;
				}
				hex += *cs - 'A' + 10;
				++cs;
			} else {
				putchar(hex);
				if (*cs == '\\'){
					--cs;
					return cs;
				}
				putchar(*cs);
				return cs;
			}
		}
		putchar(hex);
		putchar(*cs);
	} else {
		switch (*cs) {
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
			putchar(*cs);
		}
	}
	return cs;
}

int main(int argc, char **argv)
{
	if ( argc == 1){
		return 0;
	}
	char *cs;
	for (int i = 1; i< argc; ++i){
		if (i > 1){
			putchar(' ');
		}
		cs = argv[i];
		while ( *cs != '\0' ){
			if ( *cs == '\\' ){
				++cs;
				if (*(cs = escape(cs)) == '\0'){
					putchar('\n');
					return 0;
				}
			} else {
				putchar(*cs);
			}
			++cs;
		}
	}
	putchar('\n');
	return 0;
}
