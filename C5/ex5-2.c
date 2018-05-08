#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

float getch(void);
void ungetch(float);
int getint(float *);


int main()
{
	int n, s;
	float array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		printf("storing in n = %d, getint %f\n", n, array[n]);
		;

	printf("storing in n = %d, getint %f\n", n, array[n]);

	for(s=0;s<=n; s++)
		printf("%f, ",array[s]);
	printf("\n");
}

/* getint: get next integer from input into *pn */
int getint(float *pn)
{
	int c, sign;
	int temp;
	float pow;

	//while (isspace(c = getch()))		/* skip white space */
	//	;
	while (!isdigit(c = getch()) && c != EOF && c != '+' && c != '-' && c != '.') {
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

	if (c == '.')
		c = getch();

	for (pow = 1.0 ; isdigit(c); c=getch()) {
		pow *= 10.0;
		*pn = 10.0 * *pn + (c - '0');
	}

	*pn *= sign / pow;

	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100		
char buf[BUFSIZE];		/*buffer for ungetch */
int bufp = 0;			/*next free position in buf */

float getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(float c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}