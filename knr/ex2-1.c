#include <stdio.h>
#include <limits.h>
#include <float.h>

// Exercise 2-1. Write a program to determine the ranges of char , short , int , and long
// variables, both signed and unsigned , by 
// 		1) printing appropriate values from standard headers;
// 		2) by direct computation. 
// Harder if you compute them: determine the ranges of the various floating-point types.

int main(void)
{
	// 1)
	printf("-----unsigned------\n");
	printf("uchar   [%u;%u]\n",0,UCHAR_MAX);
	printf("ushort  [%u;%u]\n",0,USHRT_MAX);
	printf("uint    [%u;%u]\n",0,UINT_MAX);
	printf("ulong   [%u;%lu]\n",0,ULONG_MAX);
	printf("------signed-------\n");
	printf("char    [%d;%d]\n",CHAR_MIN,CHAR_MAX);
	printf("short   [%d;%d]\n",SHRT_MIN,SHRT_MAX);
	printf("int     [%d;%d]\n",INT_MIN ,INT_MAX );
	printf("long    [%ld;%ld]\n",LONG_MIN,LONG_MAX);
	// 2)
	printf("-----computed unsigned------\n");
	printf("uchar   [%u;%u]\n",0,(unsigned char)~0);
	printf("ushort  [%u;%u]\n",0,(unsigned short)~0);
	printf("uint    [%u;%u]\n",0,(unsigned int)~0);
	printf("ulong   [%u;%lu]\n",0,(unsigned long)~0);
	printf("------computed signed-------\n");
	printf("char    [%d;%d]\n",~((unsigned char)~0 >> 1),(unsigned char)~0 >> 1);
	printf("short   [%d;%d]\n",~((unsigned short)~0 >> 1),(unsigned short)~0 >> 1);
	printf("int     [%d;%d]\n",~((unsigned int)~0>>1) ,(unsigned int)~0>>1 );
	printf("long    [%ld;%ld]\n",~((unsigned long)~0>>1),(unsigned long)~0>>1);
	return 0;
}
