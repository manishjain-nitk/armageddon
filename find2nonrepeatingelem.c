// GEEKSFORGEEKS : http://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/#comment-15145
#include<stdio.h>
int main()
{
	int a[10],x=0,y=0,xor,bit,i;
	for(i=0;i<10;i++)
		scanf("%d",(a+i));
	xor=a[0];
	for(i=1;i<10;i++)
		xor ^= a[i];
	bit=xor & ~(xor-1);
	for(i=0;i<10;i++)
	{
		if(a[i] & bit)
			x ^= a[i];
		else
			y ^= a[i];
	}	
	printf("repeated elements are : %d, %d",x,y);
}

