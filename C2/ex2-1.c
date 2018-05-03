/*Exercise 2-1. Write a program to determine the ranges of char, short,
and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types.*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Range of the four datatypes (char, int):\n");
	//char
	printf("Range of \"char\": %d to %d\n", CHAR_MIN, CHAR_MAX);

	//int
	printf("Range of \"int\": %d to %d\n", INT_MIN, INT_MAX);

	printf("Range of qualifiers (long, unsigned)):\n");

	//unsigned char
	printf("Range of \"unsigned char\": %d to %d\n", 0, UCHAR_MAX);

	//short int, long int
	printf("Range of \"long\": %ld to %ld\n", LONG_MIN, LONG_MAX);
}