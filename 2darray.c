//AMAZON - given a 2d array having 0s and 1s find the row that contain max number of 1's if each row is sorted

#include<stdio.h>
int main()
{
	int a[5][5];
	int st=4,j,i,ind=-1;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<5;i++)
	{

		if(a[i][st] && st >-1)
		{
			while(a[i][st] && st+1)
				st--;
			ind=i;
		}
	}
	printf("\nThe row containing maximum 1's is at index %d\n",ind+1);
}
