#include <string.h>

int i = 0;
int j = 0;

/* rewrite of reverse to recursive function*/
void rreverse(char s[])
{
	char c;
	c = s[i++];
	if (c != '\0') {
		rreverse(s);
		s[j++] = c;
	}
}