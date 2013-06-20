#include<stdio.h>
int main(int argc,char* argv[])
{
	//kmp(argv[1],argv[2]);
	int i,n,n2,q,r,t,pi[1000],k;
	for(i=0;argv[1][i]!='\0';i++);
	n=i;
	k=0;
	pi[0]=0;
	for(i=1;i<n;i++)
	{

		if(argv[1][k]==argv[1][i])
			k++;
		else if(argv[1][0]==argv[1][i])
			k=1;
		else
			k=0;
		pi[i]=k;
	}
	for(i=0;i<n;i++)
	{
		printf(" %d ",pi[i]);
	}
	for(i=0;argv[2][i]!='\0';i++);
	n2=i;
	k=0;
	for(i=0;i<n2;i++)
	{
		if(argv[1][k]==argv[2][i])
			k++;
		else if(argv[1][0]==argv[2][i])
			k=1;
		else 
			k=0;
		if(k==n)
			{
				printf("\n\nmatch at %d",(i-n+1));
				k=0;
			}
	}
}
