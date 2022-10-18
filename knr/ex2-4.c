#include <stdio.h>
// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.

long unsigned int strlen(char* s1);
void squeeze(char s1[], char s2[]);

long unsigned int strlen(char* s1)
{
	int len = 0;
	while (*s1++ != '\0'){
		++len;
	}
	return len;
}

void squeeze(char* s1, char* s2)
{
	// map s2 chars
	int chars[177];
	char c;
	while ((c = *s2++) != '\0'){
		chars[c] = 1;
	}
	// map what to keep from s1
	int s1_len = strlen(s1);
	int keep[s1_len];
	int counter = 0;
	for (int i=0; i<s1_len;++i){
		if (chars[s1[i]] == 1){
			keep[i] = 0;
		} else {
			keep[i] = 1;
			++counter;
		}
	}
	// keep chars in s1 that are not in s2
	int cnt = 0;
	for (int i=0; i<s1_len;++i){
		if (keep[i]==1){
			s1[cnt] = s1[i];
			++cnt;
		}
		if (cnt == counter){
			s1[cnt] = '\0';
			break;
		}
	}
}

int main(void)
{
	char s1[] = "nidificate\t\ntest";
	char s2[] = "parsimonious\t";
	squeeze(s1,s2);
	printf("%s\n",s1);
	return 0;
}