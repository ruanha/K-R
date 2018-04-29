#include <stdio.h>

int main()
{
	int c, flag;
	
	flag = 0;
	
	while( (c=getchar()) != EOF ){
		if (c != ' '){
			putchar(c);
			flag = 0;
		}
		if (c == ' '){
			if (flag == 0){
				putchar(c);
				flag = 1;
			}
		}
	}
}
