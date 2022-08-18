#include <stdio.h>

//Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.

#include <stdio.h>

// fahr -> celsius: 5/9*(fahr-32)
// celsius -> fahr: 9/5*celsius-32


#define MIN 0
#define MAX 100
#define STEP 5

int main(void)
{
	float c = 9.0/5.0;
	printf("%s\t%s\n","celsius","fahr");
	for(int celsius=MIN;celsius<=MAX; celsius = celsius + STEP)
	{
		printf("%7d\t%4.1f\n",celsius,c*celsius+32);
	}
	return 0;
}

//fahr	celsius
//   0	  -17.8
//  20	   -6.7
//  40	    4.4
//  60	   15.6
//  80	   26.7
// 100	   37.8
// 120	   48.9
// 140	   60.0
// 160	   71.1
// 180	   82.2
// 200	   93.3
// 220	  104.4
// 240	  115.6
// 260	  126.7
// 280	  137.8
// 300	  148.9

//celsius	fahr
//      0	32.0
//      5	41.0
//     10	50.0
//     15	59.0
//     20	68.0
//     25	77.0
//     30	86.0
//     35	95.0
//     40	104.0
//     45	113.0
//     50	122.0
//     55	131.0
//     60	140.0
//     65	149.0
//     70	158.0
//     75	167.0
//     80	176.0
//     85	185.0
//     90	194.0
//     95	203.0
//    100	212.0
