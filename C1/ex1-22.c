/*Exercise 1-22. Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>

#define LIMIT 32 /* max characters per line, before we "fold" */

int main()
{
	int pos, last, c, i;
	char line[LIMIT];

	pos = 0;		//possition in char array, of length LIMIT
	last = -1;		//position of last whitespace
	while((c = getchar()) != EOF) {
		line[pos] = c;
		if (c == ' ' || c == '\t')
			last = pos;
		++pos;

		if (c == '\n') {
			line[pos] = '\0';
			printf("%s", line);
			pos = 0;
			last = -1;
		}
		if (pos == LIMIT && last >= 0) {		//we reached the LIMIT && there is a whitespace
			for (i=0; i<last; ++i)
				putchar(line[i]);
			putchar('\n');
			pos = LIMIT-i;
			for (i=0; i<LIMIT; ++i)
				line[i] = line[last+i];
			last = -1;
		}
		else if (pos == LIMIT && last < 0) {	//we reached the LIMIT && there is no whitespace
			for (i=0; i<LIMIT; ++i)
				putchar(line[i]);
			putchar('\n');
			pos = 0;
			last = -1;
		}
	}
}