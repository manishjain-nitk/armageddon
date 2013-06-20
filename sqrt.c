#include<stdio.h>
static unsigned wsqrt(int val) {
	unsigned long temp, g=0, b = 0x8000, bshft = 15;
	do {
		if (val >= (temp = (((g << 1) + b)<<bshft--))) {
			g += b;
			val -= temp;
		}
	} while (b >>= 1);
	return g;
}
int main()
{
	int n;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("sqrt of n is %d",wsqrt(n));	
}


