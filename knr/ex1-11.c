#include <stdio.h>

//Exercise 1-11. How would you test the word count program? What kinds of input are most
//likely to uncover bugs if there are any?

// my guess is double blanks, but let's test that.

// don't handle double blanks
int wo_state(void){
	int c, nn;
	c = nn = 0;
	while ((c=getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n')
			++nn;
	}
	printf("Word count: %d\n",nn);
	return nn;
}

// handle blanks
int w_state(void){
	int c, nn, blank;
	c = nn = 0;
	blank = 1;
	while ((c=getchar()) != EOF){
		if ((c == ' ' || c == '\t' || c == '\n') && !blank){
			++nn;
			blank = 1;
			continue;
		}
		if ((c == ' ' || c == '\t' || c == '\n') && blank)
			continue;
		if (blank)
			blank = 0;
	}
	printf("Word count: %d\n",nn);
	return nn;
}


int main(void){
//	printf("w/o state word count: %d\n", wo_state());
	printf("w/ state word count: %d\n", w_state());
	return 0;
}

// ran with the following cmd, taking in turns:
// ```sh
// echo "\ttesting whether
// \t
// this works
// " | bin/ex1-11
// ```

// w/o state
//w/o state word count: 8

// w/ state
//w/ state word count: 4
