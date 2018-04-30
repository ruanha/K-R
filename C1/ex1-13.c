#include <stdio.h>
#define MAXLENGTH 20

/* counts len of each word. */
/* input must be ended correctly not on EOF right after word, in which case last word will not be counted. */
/* prints a histogram of the word lengths */
int main()
{
	int wlarr[MAXLENGTH]; /* word length counting array */
	int wlen, c, i, j;
	
	for (i = 0; i < MAXLENGTH; ++i)
		wlarr[i] = 0;
	
	wlen = 0;
	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != '\t' && c != ' ' && c != ',' && c != '.' && c != ':' && c != '?')
			++wlen;
		else {
			++wlarr[wlen];
			wlen = 0;
		}
	}
	
	for (i = 0; i < MAXLENGTH; ++i) {
		printf("%3d |", i);
		for (j = 0; j < wlarr[i]; ++j)
			printf("*");
		printf("\n");
	}
}
