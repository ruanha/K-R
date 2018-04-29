#include <stdio.h>

int main()
{
	int c, count;
	
	count = 0;
	while( (c=getchar()) != EOF ){
		if (c == '\t')
			++count;
		if ( c == '\n')
			++count;
		if ( c == ' ')
			++count;
	}
	printf("%d\n", count);
}
