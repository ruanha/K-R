/* Exercise 5-3. Write a pointer version of the function strcat that we showed
in Chapter 2: strca t (s , t) copies the string t to the end of s. */

#include <stdio.h>

void pstrcat(char *, char *);
void ostrcat(char s[], char t[]);

int main()
{
	char t[] = " Some text stuff to append to s!";
	char s[1000] = "Just some text in s.";

	printf("%s\n", s);
	pstrcat(s, t);
	printf("%s\n", s);
}




void pstrcat(char *s, char *t)
{
	while ( *s != '\0' )
		s++;
	while ( (*s++ = *t++) != '\0' )
		;
}



/* original strcat: concatenate t to end of s; s must be big enough */
void ostrcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}