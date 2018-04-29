#include <stdio.h>

/* copy input to putput */
int main()
{
	int c;

	while ((c = getchar()) != EOF ) {
		putchar(c);
	}
}
