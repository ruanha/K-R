#include <stdio.h>

#define MAXLINE 1000
#define OUT 0
#define IN 1

int getline(char s[], int lim)

int main()
{
	char line[MAXLINE]
	int trail_state
	
	trail_state = IN
	while ((len = getline(line, MAXLINE)) > 0)
		for (i = len; i>=0; --i)
			
}


int getline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
