#include <stdio.h>

int my_getline(char *, int lim);

int main()
{
	char s[100];

	printf("%d\n", my_getline(s, 100));
	printf("%s\n", s);
}



/* krgetline get line into s, return length using pointer this time*/
int my_getline(char *s, int lim)
{
	int c, i;

	while ( --lim > 0 && (c=getchar()) != EOF && c!= '\n' && ++i)
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return i;
}