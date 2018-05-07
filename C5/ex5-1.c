#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int getch(void);
void ungetch(int);
int getint(int *);


int main()
{
	int n, s, array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		printf("storing in n = %d, getint %d\n", n, array[n]);
		;

	printf("storing in n = %d, getint %d\n", n, array[n]);

	for(s=0;s<=n; s++)
		printf("%d, ",array[s]);
	printf("\n");
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	int temp;

	//while (isspace(c = getch()))		/* skip white space */
	//	;
	while (!isdigit(c = getch()) && c != EOF && c != '+' && c != '-') {
		;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-' ) {
		if isdigit((c = getch())) {
			;
		}
		else
			;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100		
char buf[BUFSIZE];		/*buffer for ungetch */
int bufp = 0;			/*next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}