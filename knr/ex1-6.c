#include <stdio.h>

//Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.

//int main(void)
//{
//	int c = getchar();
//	while (c != EOF)
//	{
//		putchar(c);
//		c = getchar();
//	}
//	return 0;
//}

int main(void)
{
	int c = getchar();
	int b;
	while (b = ((c = getchar()) != EOF))
	{
		printf("c != EOF value: %d\n",b);
	}
	printf("c != EOF value: %d\n",b);
	return 0;
}
