/* Exercise 2-6. Write a function setbits(x,p,n,y)
that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void printBits(size_t const size, void const * const ptr);

int main()
{
	unsigned x = 105491;
	unsigned y = 952505;
	unsigned result;

	printBits(sizeof(x), &x);
	printBits(sizeof(y), &y);

	result = setbits(x, 6, 3, y);

	printBits(sizeof(result), &result);
}

/* setbits */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned ones;
	unsigned zeros;

	ones = ~(~0<<n)<<(p+1-n);  //ones at p to n: 11100000
	zeros = ~ones;	//zeros at p to n 111000111

	printBits(sizeof(ones), &ones);

	x = x & zeros;	//set the p-to-n bits to zero
	y = y & ones;

	//y1 = x & (~(~0 << n))<<(p-n); // set all but the p to n bits to zero: 000(p)(nnnnn)000
	//set the p to n bits to zero.

	return (x | y);
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