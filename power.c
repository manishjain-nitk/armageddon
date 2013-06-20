#include<stdio.h>
int pow(int a,int b)
{
	int res;
	if(b==0) return 0;
	if(b==1) return a;
	else
	{
		res=pow(a,b/2);
		if(b%2)
			return res*res*a;
		else
			return res*res;
	}	
	
}
int main(int argc,char* argv[])
{
	int a,b;
/*	printf("%d %d",argv[1][0]-48,argv[2][0]-48);;*/
	printf("%d",pow(argv[1][0]-48,argv[2][0]-48));
}
