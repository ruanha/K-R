/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
rightmost 1-bit in x. Explain why. Use this observation to write a faster ver-
sion of bitcount. */

#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);

int main()
{
	int i;
	for (i=1; i < 100; i += 6)
		printf("%d, %d\n", bitcount(i), bitcount2(i));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1) 
		if (x & 01)
			b++;
	return b;
}

/* bitcount2: count 1 bits in x */
int bitcount2(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}