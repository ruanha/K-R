/* Exercise 2-7. Write a function invert(x,p,n)
that returns x with the n bits
that begin at position p inverted (i.e., I changed into 0 and vice versa), leaving
the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void printBits(size_t const size, void const * const ptr);

int main()
{
	unsigned x = 105491;
	unsigned result;

	printBits(sizeof(x), &x);

	result = invert(x, 6, 3);

	printBits(sizeof(result), &result);
}

/* setbits */
unsigned invert(unsigned x, int p, int n)
{
	unsigned ones;
	unsigned zeros;

	ones = ~(~0<<n)<<(p+1-n);  //ones at p to n: 11100000
	zeros = ~ones;	//zeros at p to n 111000111

	printBits(sizeof(ones), &ones);


	return (x ^ ones);
}

// printBits : found on stackoverflow: 
// https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format#3208376
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}