#include <stdio.h>

#define MAXLINE 100

//double kr_atof(char s[]);

/* rudimentary calculator */
int main( )
{
	double sum, kr_atof(char []);
	char line[MAXLINE];
	int krgetline(char line[], int max);

	sum = 0;
	while (krgetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += kr_atof(line));
	return 0;
}