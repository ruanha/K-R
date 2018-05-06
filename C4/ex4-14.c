/* Exercise 4-14. Define a macro swap(t,x,y)
of type t. (Block structure will help.) */
#include <stdio.h>

#define swap(t,x,y) t _temp; _temp = x; x = y; y = _temp;

int main()
{
	int x=10;
	int y=2;

	printf("%d, %d \n", x, y);
	swap(int ,x,y);
	printf("%d, %d \n", x, y);
}