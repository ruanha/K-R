/*Exercise 2·3. Write the function htoi(s), which converts a string of hexadecimal 
digits (including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int htoi(char s[]);
unsigned int power(int m, int n);

int main()
{
	// these are for testing the htoi function.
    char test1[]="F00";
    char test2[]="bar";
    char test3[]="0100"; //gets interpreted as hexadecimal, i think its fine
    char test4[]="0x1";
    char test5[]="0XA";
    char test6[]="0X0C0BE";
    char test7[]="abcdef";
    char test8[]="123456";
    char test9[]="0x123456";
    char test10[]="deadbeef";
    char test11[]="zog_c";
    unsigned int hex;

    if((hex = htoi(test11)) > 0)
    	printf("\nhex = %u\n", hex);
}

/* htoi: converts a string of hexadecimal (eg. "0xF") into its (unsigned) integer value */
unsigned int htoi(char s[])
{
	int i, j;
	unsigned int n;
	int start;
	int len, dec; //dec is the decimal value of on hex char, so an int between 0..15
	char c;

	/* test if s is hexadecimal: 1) starts with 0x or 0X ? 2) all characters are hexadigits (0..9,A..F). */
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		start = 2;
	else
		start = 0;

	for(i=start; s[i] != '\0';++i) {
		if (isxdigit(s[i]))
			;
		else{
			printf("ERROR, RECIEVED STRING (\"%s\"), IS NOT A HEXADECIMAL!\n", s);
			return 0;
		}
	}
	
	/* get the decimal integer value of the hexadecimal */
	n = 0;
	j = 0;
	len = strlen(s);
	printf("length: %d\n", len);
	for ( i = len-1; i >= start; --i) {
		//printf("%c\n", s[i]);
		//if s[i] is between 0..9
		if( isdigit(s[i]) )
			dec = s[i]-'0';
		else
			dec = 10+tolower(s[i])-'a'; //assuming A..F is continuos(is that the word?)
		n = n + dec*power(16, j);
		++j;
	}


	return n;
}

/* power */
unsigned int power(int base, int n)
{
	int i;
	unsigned int p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}