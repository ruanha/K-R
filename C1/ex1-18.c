/*Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines*/

/* getline function */
/* remove trailing blanks function */

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

int main()
{
	int len, i;
	int index;
	char line[MAXLINE];
	char newline[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0 ) {
		index = len-2;
		while (index>=0 && (line[index] == '\t' || line[index] == ' '))
			--index;
		if (index < 0)
			;
		else {
			for (i=0; i<=index; ++i)
				putchar(line[i]);
			putchar('\n');
		}
	}
	return 1;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}