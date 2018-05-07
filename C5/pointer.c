#include <stdio.h>

int main()
{
	int a[10];
	int *ip;
	int i;


	for (i=0; i<10; ++i)
		a[i] = i;

	for (i=0; i<10; ++i)
		printf("%d, ", a[i]);
	printf("\n");

	ip = a;
	for (i=0; i<10; ++i)
		printf("%d, ", (*ip)++);
	printf("\n");
}