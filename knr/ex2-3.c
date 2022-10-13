#include <stdio.h>

// Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
// through 9, a through f, and A through F.

int htoi(const char hex[]);
size_t strlen(const char s[]);

size_t strlen(const char s[])
{
	size_t len = 0;
	while (*s++ != '\0' ){
		++len;
	}
	return len;
}


int htoi(const char hex[])
{
	int i = 0;
	int start = 0;
	int len = strlen(hex);
	if (len > 2){
		if (hex[1] == 'x' || hex[1] == 'X'){ 
			start = 2;
		}
	}
	for (int j=start;j<len;++j){
		if ( hex[j] >= '0' && hex[j] <= '9'){
			if ( j-start ) {
				i *= 16;
			}
			i += hex[j] - '0';
		} else if ( hex[j] >= 'a' && hex[j] <= 'f' ) {
			if ( j-start ) {
				i *= 16;
			}
			i += hex[j] - 'a' + 10;
		} else if ( hex[j] >= 'A' && hex[j] <= 'F' ) {
			if ( j-start ) {
				i *= 16;
			}
			i += hex[j] - 'A' + 10;
		} 
	}
	return i;
}

int main(void)
{
	printf("0x4 in decimal %d\n",htoi("0x4"));
	printf("0X4 in decimal %d\n",htoi("0X4"));
	printf("4 in decimal %d\n",htoi("4"));
	printf("3b in decimal %d\n",htoi("3b"));
	printf("bF in decimal %d\n",htoi("bF"));
	printf("0x0 in decimal %d\n",htoi("0x0"));
	return 0;
}