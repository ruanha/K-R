/* Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This pro-
gram is hard if you do it in full generality.) */

// unbalanced parantheses, brackets and braces: (), [], {}

// Some things to consider:
// double quotes ""
// single quotes ''
// escape sequences \" <-- escape char for double quote.
// comments

#include <stdio.h>

int main()
{
	int n_parantheses, n_brackets, n_braces;
	int in_quotes, in_comm;
	int l_number;
	int lastchar;
	int c;

	in_quotes = in_comm = 0;
	n_parantheses = n_brackets = n_braces = 0;
	l_number = 0;
	lastchar = 0;
	while ((c = getchar()) != EOF) {
		if (c== '\n')
			++l_number;
		//in quotes?
		if(c == '\"' && in_comm == 0 && lastchar != '\\' && lastchar != '\'') { 	//if we encounter a double quote " and we are 1) not in comments, 
			if (in_quotes == 0)														// 2) its not the escape sequence like: "aaa\"aaa", 3) not like: printf("%d, '"')
				in_quotes = 1;
			else
				in_quotes = 0;
		}
		//in comments?
		if(c == '*' && lastchar != '/' && in_comm == 0 && in_quotes == 0)		//if c = *, and 1) lastchar = /, 2) we are not already in comments, 3) not in quotes
			in_comm = 1;
		else if(c == '/' && lastchar != '*' && in_comm == 1 && in_quotes == 0)
			in_comm = 0;
		if (c=='+')
			printf("%d %d", in_quotes, in_comm);

		//open parantheses?
		if(c == '(' && in_quotes == 0 && in_comm == 0)
			++n_parantheses;
		if(c == ')' && in_quotes == 0 && in_comm == 0)
			--n_parantheses;
		//open brackets?
		if(c == '[' && in_quotes == 0 && in_comm == 0)
			++n_brackets;
		if(c == ']' && in_quotes == 0 && in_comm == 0)
			--n_brackets;
		//open braces?
		if(c == '{' && in_quotes == 0 && in_comm == 0)
			++n_braces;
		if(c == '}' && in_quotes == 0 && in_comm == 0)
			--n_braces;
	}

	if (n_parantheses+n_brackets+n_braces != 0)
		printf("\nERROR FOUND\n");
	else
		printf("\nprogram looks clean\n");
	printf("Number of open parantheses, brackets and braces: %3d %3d %3d\n", n_parantheses, n_brackets, n_braces);
}