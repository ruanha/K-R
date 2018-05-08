#include <stdio.h>

int strend(char *, char *);

int main(void)
{
	char t1[] = "text";
	char t2[] = "more";
	char t3[] = "not";

	char s1[] = "some text";
	char s2[] = "some more";
	char s3[] = "dlfkfpsdp";

	printf("%d\n", strend(s1, t1));
	printf("%d\n", strend(s2, t2));
	printf("%d\n", strend(s3, t3));
}

int strend(char *s, char *t)
{
	int len_s=0;
	int len_t=0;


	while ( *s++ != '\0')
		len_s++;

	while ( *t++ != '\0')
		len_t++;

	if (len_t > len_s)
		return 0;

	s = s - len_t-1;

	t = t-len_t-1;

	

	while ( (*s++ == *t++) && *s != '\0' )
		;
	if (*s == '\0')
		return 1;
	else
		return 0;
}