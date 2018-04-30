#include <stdio.h>

#define MAXLENGTH 1000
#define MINLENGTH 5

int getline2(char line[], int length);

int main()
{
	int len;
	char line[MAXLENGTH];	
	
	while ((len = getline2(line, MAXLENGTH)) > 0)
		if (len > MINLENGTH)
			printf("%s", line);
}

int getline2(char s[MAXLENGTH], int lim)
{
	int i, c;	
	
	for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
