#include <stdio.h>

//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
//in its input.

#define SHIFT 0
#define MAX_LENGTH 128-SHIFT

void freq(int[]);

void freq(int f[]){
	int c;
	while ((c=getchar()) != EOF){
		++f[c-SHIFT];
	}
}

int main(void){
	int f[MAX_LENGTH];
	for (int i=0; i<MAX_LENGTH; ++i)
		f[i] = 0;
	freq(f);
	for (int i=0;i<MAX_LENGTH;++i){
		printf("%c ",i+SHIFT);
		for (int j=0;j<f[i];++j){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


