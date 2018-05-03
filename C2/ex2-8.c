/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions.
*/

/*By rotated they mean that the bits that dissapear when shifted, enter again on the other side:
 like this:  1100 << 1 --> 1001
 Thank you Stackoverflow :) */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void printBits(size_t const size, void const * const ptr);

int main()
{
	rightrot(123456, 101);
}

unsigned rightrot(unsigned x, int n)
{
	int bit;
	int i;

	printBits(sizeof(x), &x);

	for (i = 0; i < n; i++) {
		bit = (x & 1);
		if (bit == 1)
			x = (x >> 1) | ~(~0U >> 1); //0U = 0 "converted" to an unsigned int (p. 44)
		else
			x = (x >> 1);
	}

	printBits(sizeof(x), &x);

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