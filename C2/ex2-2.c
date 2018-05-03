/* Exercise 2-2. Write a loop equivalent to the for loop without using && or ||. */
/* for (i=O; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c; */

#include <stdio.h>
#define YES 1
#define NO 0

int main()
{
	int c, i;
	int lim = 10;
	int stop = NO;
	char s[lim];

	i=0;
	while(stop == NO){
		if(i >= lim-1)
			stop = YES;
		else
			c = getchar();
		if(c == '\n')
			stop = YES;
		else if(c == EOF)
			stop = YES;
		else
			s[i] = c;
		if (stop == YES)
			s[i] = '\0';
		++i;
	}
	printf("%s\n", s);

}