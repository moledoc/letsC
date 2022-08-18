#include <stdio.h>

//Exercise 1-3. Modify the temperature conversion program to print a heading above the table.

// fahr -> celsius: 5/9*(fahr-32)

#define MIN 0
#define MAX 300
#define STEP 20

int main()
{
	float c = 5.0/9.0;
	printf("%s\t%s\n", "fahr","celsius");
	for(int fahr=MIN; fahr<=MAX; fahr = fahr + STEP)
	{
		printf("%4d\t%7.1f\n", fahr, c*(fahr-32.0));
	}
	return 0;
}
