#include<stdio.h>
int f(int d,int e)
{
	if(e==0||d==0)return 0;
	if(e==1)return d;
	return f(d-1,e)+f(d-1,e-1)+1;
}


int main()
{
	int i=0,j=0,k;
	printf("no. of floors and no. of eggs : ");
	scanf("%d",&k);
	scanf("%d",&j);
	if(k&&j)
	while(f(++i,j)<k);
	printf("no. of drops required : %d", i);
	return 0;
}
