/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine. */

#include <stdio.h>
#include <limits.h>

#define TEST -6234500

void itoar(int n, char s[]);

int main()
{
	int n = TEST;
	char s[26];

	itoar(n, s);
	printf("%s\n", s);
}

int i = 0;
/* itoar: integer to a string recursive version of itoa */
void itoar(int n, char s[])
{
	if (n < 0) {
		s[0] = '-';
		n = -n;
		++i;
	}

	if (n / 10) {
		itoar(n / 10, s);
	}
	s[i++] = '0' + (n % 10);
	s[i+1] = '\0';
}