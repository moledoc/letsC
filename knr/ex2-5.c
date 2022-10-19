#include <stdio.h>

// Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the
// location.)

#define NUMBER_OF_CHARS 177


int any(const char *s1, const char *s2);
void printer(char *s1, const char *s2);

int any(const char *s1, const char *s2)
{
	int chars[NUMBER_OF_CHARS];
	// map s2 chars
	char c;
	while( (c=*s2++) != '\0'){
		chars[c] = 1;
	}
	// solve ex
	int counter = 0;
	while (chars[*s1] != 1 && *s1 != '\0'){
		++s1;
		++counter;
	}
	if (*s1 != '\0') {
		return counter;
	}
	return -1;
}

void printer(char *s1, const char *s2)
{
	int pch = any(s1, s2);
	while (pch != -1){
		printf("\tkey=%s; str key-char in s1 is '%d': '%s'\n",s2,pch,s1);
		s1+=pch+1;
		pch = any(s1,s2);
	}	
}

int main(void)
{

	char *s1 = "str";
	char *s2 = "keyr";
	printf("Set 1:\n");
	printer(s1,s2);

	s1 = "test";
	s2 = "test";
	printf("Set 2:\n");
	printer(s1,s2);

	s1 = "This is a sample string";
	s2 = "aeiou";	
	printf("Set 3:\n");
	printer(s1,s2);
	return 0;
}