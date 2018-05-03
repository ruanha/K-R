/* Exercise 2-10. Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>

int lower2(char s[]);

int main()
{
	char s[]= "To Lowskj LASKDK Dkj dlsaksjdfJKj198  k., pLEasE!";
	lower2(s);
	printf("%s\n", s);
}

int lower2(char s[])
{
	int i = 0;

	while (s[i] != '\0') {
		s[i] = ( 'A' <= s[i] && s[i] <= 'Z' ) ? 'a' + s[i] - 'A' : s[i];
		i++;
	}
	return 1;
}
