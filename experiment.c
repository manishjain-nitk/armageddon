#include<stdio.h>

int main()
{
	int a __attribute__ ((aligned (1))) = 0;
//int a : 16;
	a=(200*200)/200;
	printf("%d",a);
	return 0;
}
