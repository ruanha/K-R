#include <stdio.h>

/* counts number of lines (number of newline characters) in input */

int main()
{
	int c, nl;
	
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
