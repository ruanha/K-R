#include <stdio.h>

int main()
{
	unsigned x = 07;
	int n = 2;
	int p = 4;

	printf("%d\n", ((~(~0 << 2))) << 2);
}
