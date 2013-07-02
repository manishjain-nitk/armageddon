#include<stdio.h>
#include<string.h>
/*int main()
{
*//*	int *ptr = 0; // Error
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
main(){	int i;
	float a=3.7;
	char *ptr;
	ptr=(char *)&a;
	for(i=0;i<=3;i++)
		printf("%d ",*ptr++);
}
/*	 {
		typedef union {
			int a;
			char b[10];
			float c;
		}
		Union;
		Union x,y = {100};
		x.a = 50;
		strcpy(x.b,"hello");
		x.c = 21.50;
		printf("Union x : %d %s %f n",x.a,x.b,x.c);
		printf("Union y : %d %s %f n",y.a,y.b,y.c);
	}
	return 0;
*/
/*	float a=7;
	int b=3;
	while(1)
	{
		scanf("%f",&a);
		scanf("%d",&b);
	printf("\n");
	printf("float of a - %f",a);
	printf("\n");
	printf("decimal of a - %d",a);
	printf("\n");
	printf("float of b - %f",b);
	printf("\n");
	printf("decimal of b - %d",b);
	printf("\n");
	}
*//*	return 0;
}*/
/*
#include<stdio.h>
//main()
//{
//	int a=744;
//	int *num=&a;
//	printf("%d %d",*((char *)num),*((char *)num+1));
//
//}
//iint main()
//i{
//i	int a=2,*f1,*f2;
//i	f1=f2=&a;
//i	*f2+=*f2+=a+=2.5;
//i	printf("\n%d %d %d",a,*f1,*f2);
//i}

int main()
{
	int a=2;
	if(a==(1,2))
		printf("hello ");
	if(a==1,2)
		printf("world ");
	return 0;
}
//00000001 01101000*/
