#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);
void itos(int n, char s[]);


int main()
{
	char s[12]; //must be large enough to hold INT_MIN as a string (including the '-' and '\0')

	itos(INT_MIN, s);
	printf("%d, %d\n", INT_MAX, INT_MIN);
	printf("%s\n", s);
}

/* int to string */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) > 0)	{	/* save sign */
		n = -n;				/* set to negative */
	}
	i = 0;
	do {
		s[i++] = -1*(n % 10) + '0';
	} while ((n/=10) < 0);
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