/* Exercise 2-5. Write the function any (s 1, s2 ), which returns the first location
in the string s 1 where any character from the string s2 occurs, or -1 if s 1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location. */

#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);

int main()
{
	char s1[MAXLINE];
	char s2[MAXLINE];
	int result;
	int c;
	int i;

	i = 0;
	while((c=getchar()) != EOF && i < MAXLINE-1 && c != '\n'){
		s1[i++] = c;
	}
	s1[i] = '\0';

	i = 0;
	while((c=getchar()) != EOF && i < MAXLINE-1 && c != '\n'){
		s2[i++] = c;
	}
	s2[i] = '\0';

	if ((result = any(s1, s2)) >= 0)
		printf("%d\n", result);
	else
		printf("No match\n");
	
}

/* any */
int any(char s1[], char s2[])
{
	int i, j, k;

	j = 0;
	for ( i = 0; s1[i] != '\0'; i++)
		for ( k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				return i;
	return -1;
}
