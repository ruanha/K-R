/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and
strncmp; which operate on at most the first n characters of their argument
strings. For example, strncpy (s,t , n) copies at most n characters of t to s.
Full descriptions are in Appendix B. */

#include <stdio.h>

char * my_strncp(char *, char *, int n);
char * my_strncat(char *s, char *t);
int my_strncmp(char *, char *, int n);

int main()
{
	char s1[100];
	char t1[] = "my little string";

	char t2[] = "-append me";

	char t3[] = "my little comparison";

	my_strncp(s1, t1, 50);
	printf("%s\n", s1);

	my_strncat(s1, t2);
	printf("%s\n", s1);

	printf("%d\n", my_strncmp(t1, t3, 15));

}


/* copy at most n characters of string t to s; return s.
Pad with '\ 0's if t has fewer than n characters */
char * my_strncp(char *s, char *t, int n)
{
	int i;

	for (i = 0; i<n; i++)
		*s++ = *t++;

	return s;
}

/* concatenate string t to end of string s; return s. */
char * my_strncat(char *s, char *t)
{
	while (*s++)
		;
	s -= 1;
	while ( ( *s++ = *t++ ) )	// when we reach '\0' then the condition is False (== 0)
		;
	return s;
}

/* compare at most n characters of string s to string t;
return <0 if s<t, 0 if s==t, or >0 if s>t. */
int my_strncmp(char *s, char *t, int n)
{
	for (; *s == *t ; s++, t++)
		if ( *s == '\0' || --n <=0 )
			return 0;
	return *s-*t;	//lexicological comparison of the last letters
}