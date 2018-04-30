/* the actual excersise says to modify the main routine, but i can't see how that would work without completely
redoing the program, so will make my changes in the getline() which seems most natural. */

#include <stdio.h>

#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
	int len;			/* current line length */
	int max;			/* max length so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%d %s", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-1) {
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
	}
	s[j] = '\0';
	return i;
}

/* copy: copy line 'from' into 'to'; assume "to" is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
