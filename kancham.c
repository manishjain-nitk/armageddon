/*
//#include<stdio.h>
//int main()
//{
//	int m=5;
////	printf("%d %u\n",m ,p);
////	++*p++;
////	printf("%d %u\n",m ,p);
//	m={5,4,3,2,1,3};
//	return 0;
//}
//
//
*/
#include<stdio.h>
struct e{ int a:5,b:5,c:6;};
int main()
	{
		struct e a={1,1,133};
		struct e *p=&a;
		printf("%d %p\n",(*p).c,p);
		p++;
		printf("%p\n",p);

	
	}
