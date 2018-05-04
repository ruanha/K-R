#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itob(int n, char s[], int b);


int main()
{
	char s[12]; //must be large enough to hold INT_MIN as a string (including the '-' and '\0')
	int n = -1239;

	printf("%d\n", n);
	itob(n, s, 35);
	//printf("%d, %d\n", INT_MAX, INT_MIN);
	printf("%s\n", s);
}

/* int to string */
void itob(int n, char s[], int b)
{
	int i, sign;
	char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if ((sign = n) < 0)	{	/* save sign */
		n = -n;
	}
	i = 0;
	do {
		s[i++] = symbols[n % b];	/* substitute the remainder with its symbolic representation */
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* rewrite of reverse from ex1-19 */
void reverse(char s[])
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}