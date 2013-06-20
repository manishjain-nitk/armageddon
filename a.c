#include<stdio.h>
int main()
{
	if(fork())
	{
		printf("Manish ");
	}
	else
	{
		printf("Jain");
	}
}
