//ALGORITHMICA - COUNT NUMBER OF ZEROS IN STARTING OF AN ARRAY O(lgn)

#include<stdio.h>
#define MAX 10
int main()
{
	int arr[MAX],i,low,high,mid;
	for(i=0;i<MAX;i++)
		scanf("%d",(arr+i));
	printf("finished");
	fflush(stdout);
	high=MAX;
	low=0;
	while((high-1)!=low)
	{
		mid=(high+low)/2;
		if(arr[mid]!=0)
			high=mid;
		else
			low=mid;
		printf("mid is %d, low is %d, high is %d ",mid, low,high);
		fflush(stdout);
	}
	if(arr[high])
	printf("number of zeros : %d",high);
	else
	printf("number of zeros : %d",low);
}
