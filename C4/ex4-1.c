#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int krgetline (char line [], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";	/* pattern to search for */



/* find all lines matching pattern */
int main( )
{
	char line[MAXLINE];
	int found = 0;
	int index = 0;

	while (krgetline(line, MAXLINE) > 0)
		if ( (index = strrindex(line, pattern)) >= 0) {
			printf("%d, %s", index, line);
			found++;
		}
	return found;
}