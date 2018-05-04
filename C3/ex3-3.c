/* Exercise 3-3. Write a function expand (s 1, s2) that expands shorthand nota-
tions like a-z in the string s1 into the equivalent complete list abc ... xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally. */

// not sure what "Arrange that a leading or trailing - is taken literally" means...

#include <stdio.h>
#include <string.h> //strlen()
#include <ctype.h> //tolower()

int expand(char s1[], char s2[]);

int main()
{
	char s1[] = "some tests:\na-z.\nand a-b-c\nand a-z0-9\n-a-z\nbut don't do tralala-zc please.";
	char s2[strlen(s1)*26];

	expand(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", s2);

}

/* s1 --> s2 */
/* expands a-z and 0-9 if found in string*/
int expand(char s1[], char s2[])
{
	int i, j, k;
	char alpha[] = "BCDEFGHIJKLMNOPQRSTUVWXY";
	char numeric[] ="12345678";

	for (i=0, j=0; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
			if (s1[i-1] == 'a' && s1[i+1] == 'z' && (i==1 || isspace(s1[i-2])))
				for (k = 0; alpha[k] != '\0'; k++) {
					s2[j++] = tolower(alpha[k]);
				}
			else if (s1[i-1] == '0' && s1[i+1] == '9' && (i==1 || isspace(s1[i-2])))
				for (k = 1; k<=8; k++)
					s2[j++] = '0'+k;
			else if (s1[i-1] == 'A' && s1[i+1] == 'Z' && (i==1 || isspace(s1[i-2])))
				for (k = 0; alpha[k] != '\0'; k++)
					s2[j++] = alpha[k];
			else
				s2[j++] = s1[i];
		}
		else
			s2[j++] = s1[i];
	}

	s2[j] = '\0';
}