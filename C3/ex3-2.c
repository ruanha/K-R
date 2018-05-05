/* Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \ t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters. */

#include <stdio.h>
#include <string.h> //for strlen

int escape(char t[], char s[]);
int revescape(char t[], char s[]);

int main()
{
	char t[] = "here is a tab directly after the word	. How did that\nlook?";
	char s[strlen(t)*2];
	char s[strlen(t)];

	escape(t, s);
	printf("s: %s\n", s);

	revescape(s, u);
	printf("u: %s\n", u);

}

/* escape: copies the string t to s, and converts characters \n \t into visible escape
characters. it uses a switch  */
int escape(char t[], char s[])
{
	int i, j;

	for (i=0, j=0; i<strlen(t); i++, j++) {
		switch (t[i]) {
			case '\t':
				s[j] = '\\';
				j++;
				s[j] = 't';
				break;
			case '\n':
				s[j] = '\\';
				j++;
				s[j] = 'n';
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

/* reverse of escape */
int revescape(char s[], char u[])
{
	int i, j;

	i=0;
	for (i=0, j=0; i<strlen(t); i++, j++)
}