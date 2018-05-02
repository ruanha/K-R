/*Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference?*/

#include <stdio.h>
#define TABSIZE 8

int circular(int n, int c);

int main()
{
	int c;
	int nspaces;
	int distance;

	distance = TABSIZE;
	nspaces = 0;
	while((c=getchar()) != EOF) {
		if(c == ' ') {
			++nspaces;
			if(nspaces > 1 && nspaces == distance) {
				putchar('\t');
				nspaces = 0;
				distance = TABSIZE;
			}
			else if(nspaces == 1 && nspaces == distance) {
				putchar(' ');
				nspaces = 0;
				distance = TABSIZE;
			}
		}
		else if(c == '\t') {
			putchar(c);
			nspaces = 0;
			distance = TABSIZE;
		}
		else if(c == '\n'){
			putchar('\n');
			nspaces = 0;
			distance = TABSIZE;
		}
		else {
			if(nspaces > 0) {
				while(nspaces > 0) {
					putchar(' ');
					--nspaces;
					distance = circular(distance, TABSIZE);
				}
				putchar(c);
				distance = circular(distance, TABSIZE);
			}
			else {
				putchar(c);
				nspaces = 0;
				distance = circular(distance, TABSIZE);
			}
		}
	}
}

/*  circles between values c to 1 */
int circular(int n, int c)
{
	if (n == 0)
		return c;
	else
		return n-1;
}