#include<stdio.h>
int main()
{
/*	int *ptr = 0; // Error
	*ptr;// Error
	printf("%d",(int)*ptr);
	char a[]="yahoo*";*/
//	printf("%*.2s",printf("manish"),"manish");
/*	printf("%s",);*/
/*	int a=2;
	printf("%d",a<<-1);*/
/*	int x=3;
	int *p;
	p=&x;
	&x <-- p;
	printf("%d",x);
*/
	int i;
	float a=5.2;
	char *ptr;
	ptr=(char *)&a;
	for(i=0;i<=3;i++)
		printf("%d ",*ptr++);
	
	return 0;

}
