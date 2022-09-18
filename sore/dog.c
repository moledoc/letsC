#include <stdio.h>

// README dog is basic implementation of `cat`.

int main(int argc, char **argv)
{
	if (argc == 1){
		return 0;
	}
	for (int i =1; i<argc; ++i){
		FILE *f;
		f = fopen(argv[i],"r");
		char c;
		while ((c=getc(f)) != EOF){
			putchar(c);
		}
		fclose(f);
	}
    return 0;
}
