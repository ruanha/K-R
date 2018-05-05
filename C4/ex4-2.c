#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
int main(void)
{
	double sum, kr_atof(char []);
	char line[MAXLINE];
	int krgetline(char line[], int max);

	sum = 0;
	while (krgetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += kr_atof(line));
	return 0;
}