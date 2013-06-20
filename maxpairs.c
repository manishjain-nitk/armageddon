#include<stdio.h>
#define MAX 100
int main()
{
	int T[MAX]={0},S[MAX]={0};
	int no_of_cups,no_of_saucers;
	int i=-1,j=0;
	int count=0;
	do
	{
		i++;
		scanf("%d",&T[i]);
		}
	while(T[i]);

	no_of_cups=i;
	i=-1;
	do
	{
		i++;
		scanf("%d",&S[i]);
		}
	while(S[i]);
	no_of_saucers=i;
	i=0;
	while(i<no_of_cups && j<no_of_saucers)
	{
		if(T[i]<=S[j])
		{
			count++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	printf("number of pairs is : %d",count);
}
