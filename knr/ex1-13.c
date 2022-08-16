#include <stdio.h>

//Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
//easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

// assume words no longer than MAX_LENGTH
#define MAX_LENGTH 25

void freq(int[]);

void freq(int f[]){
	int in_word, c,l;
	c = in_word = l = 0;
	while ((c=getchar()) != EOF){
		if (!in_word && (c != ' ' || c != '\t' || c != '\n' )){
			in_word = 1;
		}
		if (in_word && (c != ' ' || c != '\t' || c != '\n' ))
			++l;
		if (in_word && (c == ' ' || c == '\t' || c == '\n' )){
			++f[l-1];
			l = in_word = 0;
		}
	}
}

int main(void){
	int f[MAX_LENGTH];
	for (int i=0; i<MAX_LENGTH; ++i)
		f[i] = 0;
	freq(f);
	for (int i=0;i<MAX_LENGTH;++i){
		printf("%3d ",i);
		for (int j=0;j<f[i];++j){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


