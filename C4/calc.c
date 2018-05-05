/* ex4-3, ex4-4, ex4-5, ex4-6, ex4-7, ex4-8, ex4-9, ex4-10 */
// ex4-3 check
// ex4-4 check
// ex4-5 check
// ex4-6 check
// ex4-7 ungets

#include <stdio.h>
#include <stdlib.h> //atof()
#include <math.h>

#define MAXOP 100	// max size of operand or operator
#define NUMBER '0'	// signal that a number was found

int getop(char []);
void push(double);
double pop(void);
int setp(int pos);
void ungets(char s[]);

double varvalues[26];
int last;
double l;

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2, op3;
	char s[MAXOP];
	char vnames[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);		// modulus(%) is an integer operator
				else
					printf("error: zero divisor\n");
				break;
			case '?':
				printf("top element: \t%.8g\n", op2 = pop());
				push(op2);
				break;
			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 'w':
				op2 = pop();
				op3 = pop();
				push(op2);
				push(op3);
				break;
			case 'c':
				setp(0);
				break;
			case 's':
				op2 = sin(pop());
				push( op2 );
				break;
			case 'e':
				op2 = exp(pop());
				push(op2);
				break;
			case 'p':
				op2 = pop();
				push( pow(op2, pop()) );
				break;
			case 'l':
				printf("%g \n", l);
				break;
			case '=':
				varvalues[last-'A'] = pop();
				break;
			case 'u':
				ungets("1 1 +\n");
				break;
			case '\n':
				printf("\t%.8g\n", l = pop());
				break;
			default:
				if ( 'A' <= type && type <= 'Z') {
					push(varvalues[type-'A']);
					last = type;
				}
				else
					printf("error: unknown command %c\n", type);
				break;
		}
	}
	return 0;
}


#define MAXVAL 100	// maximum depth of val stack

int sp = 0;			// next free stack position
double val[MAXVAL];	// value stack

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int setp(int pos)
{
	sp = pos;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] =c = getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
//char buf[BUFSIZE];	/*buffer for getch/ungetch */ 
int bufp = 0;		/* next free position in buf */
int buf[BUFSIZE];

/* get a (possibly pushed back) character */
int getch(void)		
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}

#include <string.h>

/* gets a string, pushes it to buf */
void ungets(char s[])
{
	int i=0;
	char c;
	while ((c = s[i++]) != '\0')
		ungetch(c);
}