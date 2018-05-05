#include <ctype.h>
#include <math.h> // pow

/* kr_atof: convert string s to double */
double kr_atof(char s[])
{
	double val, power;
	int i, sign, exp_sign, exponent;

	for ( i = 0; isspace(s[i]); i++) /* skip leading white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	/* uses scientific notation */
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		exp_sign = s[i] == '-' ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exponent = 0; isdigit(s[i]); i++)
			exponent = exponent * 10 + (s[i] - '0');
		val = val * pow(10.0, exp_sign*exponent);
	}
	return sign * val / power;
}