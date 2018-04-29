#include <stdio.h>

/* print Celsius-Fahrenheit table for celsius = 0, 20, ..., 300 */

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("Celsius Fahrenheit\n");
	while (celsius <= upper) {
		fahr = (9.0*celsius/5.0) + 32.0;
		printf("%7.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
