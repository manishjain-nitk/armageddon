#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>
int main(int argc,char* argv[])
{
	int i,j,k,len_str,len_pat;
	for(i=0;argv[2]!='\0';i++);
	len_pat=i;
	int pi[len_pat];
	for(i=0;argv[1]!='\0';i++);
	len_str=i;
//	pi=(int *)malloc(sizeof(int)*len_pat);
	printf("\n");
	pi[0]=-1;
	k=-1;
	for(i=1;i<len_pat;i++)
	{
		while(k>-1 && argv[2][k+1]!=argv[2][i])
			k=pi[k];
		if(argv[2][k+1]==argv[2][i])
			k=k+1;
		pi[i]=k;
	}
	for(i=0;i<len_pat;i++)
	{
		printf(" %d ",pi[i]);
	}

		
	
}
