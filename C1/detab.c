/*Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parame-
ter?*/

/* there is no environment tab size */
#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 1000

int getline(char s[], int lim);
int circular(int n, int c);

main()
{
	int len, i, j;
	char line[MAXLINE];
	int dist_from_col;

	while ((len = getline(line, MAXLINE)) > 0 ) {
		dist_from_col = TABSIZE;
		for(i=0; i<len; ++i){
			if (line[i] == '\t') {
				for (j=0; j<dist_from_col; j++) 
					putchar(' ');
				dist_from_col = TABSIZE;
			}
					
			else {
				printf("%c", line[i]);
				dist_from_col = circular(dist_from_col, TABSIZE);
			}
		}
	}
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

/*  circles between values c to 1 */
int circular(int n, int c)
{
	if (n == 0)
		return c;
	else
		return n-1;
}