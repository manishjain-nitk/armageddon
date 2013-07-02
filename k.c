#include<stdio.h>

int main()
{
	int (*p)()=main;
	printf("\n%p\n",main);
	printf("\n%d\n",main);
	int main=2;
	printf("\n%p\n",main);
	printf("\n%d\n",main);
	getchar();
	(*p)();
};
