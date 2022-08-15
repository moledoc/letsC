#include <stdio.h>

//Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
//that is, from 300 degrees to 0.
// fahr -> celsius: 5/9*(fahr-32)

#define MIN 0
#define MAX 300
#define STEP 20

int main()
{
	float c = 5.0/9.0;
	printf("%s\t%s\n", "fahr","celsius");
	for(int fahr=MAX; fahr>=MIN; fahr = fahr - STEP)
	{
		printf("%4d\t%7.1f\n", fahr, c*(fahr-32.0));
	}
	return 0;
}

//fahr	celsius
// 300	  148.9
// 280	  137.8
// 260	  126.7
// 240	  115.6
// 220	  104.4
// 200	   93.3
// 180	   82.2
// 160	   71.1
// 140	   60.0
// 120	   48.9
// 100	   37.8
//  80	   26.7
//  60	   15.6
//  40	    4.4
//  20	   -6.7
//   0	  -17.8
