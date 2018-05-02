/* Exercise 1-23. Write a program to remove all comments from a C program.
Don't forget to handle "quoted strings" and character constants properly. C com-
ments do not nest. */
#include <stdio.h>

#define OUT 0
#define IN 1
#define MAXLINE 1000

int getline(char s[], int lim);
int iscommentin(char s[], int index);
int iscommentout(char s[], int index);

int main()
{
	char line[MAXLINE];
	int state, len, i;
	int in_quote;

	state = OUT;
	in_quote = OUT;
	while ((len = getline(line, MAXLINE)) > 0 )
		for (i=0; i<len; ++i) {
			if (state == OUT) {
				if (line[i] == '"' && in_quote == OUT && line[i-1] !='\'' && line[i+1] !='\'')
					in_quote = IN;
				else if (line[i] == '"' && in_quote == IN && line[i-1] !='\'' && line[i+1] !='\'')
					in_quote = OUT;
				if (iscommentin(line, i) > 0 && in_quote == OUT ) {
					state = IN;
					++i;
				}
			}
			else
				if (iscommentout(line, i) > 0) {
					state = OUT;
					i = i+2;
				}
			if (state == OUT)
				putchar(line[i]);
		}
	printf("%d", state);



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

int iscommentin(char s[], int index)
{
	if (s[index] == '/' && s[index+1] == '*')
		return 1;
	else
		return 0;
}

int iscommentout(char s[], int index)
{
	if (s[index] == '*' && s[index+1] == '/')
		return 1;
	else
		return 0;
}