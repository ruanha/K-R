#include <stdio.h>
#define MAXLINE 1000

int reverse(char r[], char s[] , int len);
int getline(char s[], int lim);

int main()
{
	char line[MAXLINE];
	char revline[MAXLINE];
	int len;

	while ((len = getline(line, MAXLINE)) > 0 ) {
		reverse(revline, line, len);
		printf("%s", revline);
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

int reverse(char r[], char s[], int len)
{
	int i, j;

	j=0;
	for(i=len-2; i>=0; --i)
		r[j++] = s[i];
	r[j] = '\n';
	r[j+1] = '\0';

	return 1;
}