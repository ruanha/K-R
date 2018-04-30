#include <stdio.h>
#define MAXCHAR 'z'-'a'

int main()
{
	int chararr[MAXCHAR];
	int i, j, c;
	
	for (i = 0; i <= MAXCHAR; ++i)
		chararr[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			++chararr[c-'a'];
	}
	
	printf("\n");
	for (i = 0; i <= MAXCHAR; ++i) {
		printf("%c | ", 'a'+i);
			for (j = 0; j < chararr[i]; ++j)
				printf("*");
		printf("\n");
	}
		
}
