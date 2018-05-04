/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only one
test inside the loop and measure the difference in run-time. */

/* Had to do some googling to find how to do the "measure the difference in run-time"
part of the excersize. Will use the time.h header, even though it is not introduced yet
but is there any other way that makes sense?
*/

#include <stdio.h>
#include <time.h>

#define MAX 100

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int testdata[MAX];
	int i, j;
	double time_spent;
	clock_t begin, end;

	for (i = 0; i < MAX; ++i)
		testdata[i] = i;

	/* test original binsearch */
	begin = clock();
	for (i=0; i<MAX; i++)
		printf("test%d: %d\n", i, binsearch(i, testdata, MAX));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);

	/* new binsearch */
	begin = clock();
	for (i=0; i<MAX; i++)
		printf("test%d: %d\n", i, binsearch2(i, testdata, MAX));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
}


/* binsearch: find x in sorted array v; v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid -1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* binsearch2: find x in sorted array v; v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;

	while(low < high) {
		mid = (low+high) / 2;
		if(x <= v[mid]) 
		  high=mid;
		else 
		  low = mid + 1;
	}
	if ( v[low] == x) 	// if found
		return low;
	else
		return -1;
}