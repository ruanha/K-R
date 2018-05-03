/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
each character in s1 that matches any character in the string s2 */

#include <stdio.h>
#define MAXLINE 1000

int squeeze(char s1[], char s2[]);

int main()
{
	char s1[MAXLINE];
	char s2[MAXLINE];
	int c;
	int i;

	i = 0;
	while((c=getchar()) != EOF && i < MAXLINE-1 && c != '\n'){
		s1[i++] = c;
	}
	s1[i] = '\0';

	i = 0;
	while((c=getchar()) != EOF && i < MAXLINE-1 && c != '\n'){
		s2[i++] = c;
	}
	s2[i] = '\0';

	squeeze(s1, s2);
	printf("%s\n", s1);
	
}

/* squeeze */
int squeeze(char s1[], char s2[])
{
	int i, j, k;
	int found;

	found = 0;
	j = 0;
	for ( i = 0; s1[i] != '\0'; i++) {
		for ( k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				found = 1;
		if (found == 0)
			s1[j++] = s1[i];
		else
			found = 0;
	}

	s1[j] = '\0';
}
