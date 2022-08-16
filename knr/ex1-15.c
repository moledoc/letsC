#include <stdio.h>

//Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
//for conversion.

// fahr -> celsius: 5/9*(fahr-32)
// celsius -> fahr: 9/5*celsius-32
float f2c(float);
float c2f(float);

float f2c(float f)
{
	return 5.0/9.0*(f-32);
}


float c2f(float c)
{
	return 9.0/5.0*c+32;
}

int main(void){
	printf("110 fahr   = %4.1f celsius\n",f2c(110.0));
	printf("35 celsius = %4.1f fahr\n",c2f(35.0));
	return 0;
}
