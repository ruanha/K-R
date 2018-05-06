#include <stdio.h>

void rreverse(char s[]);
void reverse(char s[]);

int main()
{
	char s[] = "a string to reverse";

	rreverse(s);
	printf("%s\n", s);
}




#include <string.h>



/* rewrite of reverse to recursive function*/
void rreverse(char s[])
{
	static int i = 0;
	static int j = 0;

	char c;
	c = s[i++];
	if (c != '\0') {
		rreverse(s);
		s[j++] = c;
	}
}