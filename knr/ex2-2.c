#include <stdio.h>

// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
// s[i] = c;

int main (void) 
{
    int c, i;
    int lim = 10;
    char s[lim];
    for (i=0; (i < (lim-1)) * ((c=getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;
    printf("%s\n",s);
    return 0;
}