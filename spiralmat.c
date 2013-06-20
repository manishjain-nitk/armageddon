#include<stdio.h>
#define SIZE 100
int main()
{
	char a[SIZE][SIZE]={0}; int j,i;
	int ctr,size;
	scanf("%d",&size);
	for(i=0;i<size;printf("\n\n %d row\n\n",i+1),fflush(stdout),i++)
		for(j=0;j<size;fflush(stdout),fflush(stdin),j++)
			scanf(" %c ",(*(a+i)+j));


	fflush(stdout);
	//SPIRaL ORDER PRINT
	i=-1,j=-1;
	ctr=0;
	while(ctr<size)
	{
		i++;
		j++;
		while(j<(size-ctr))
		{
			printf(" %c ",a[i][j++]);
		}
		j--;
		i++;
//		printf("\n");
		while(i<(size-ctr))
		{
			printf(" %c ",a[i++][j]);
		}
		i--;
		j--;
//		printf("\n");
		while(j>=ctr)
		{
			printf(" %c ",a[i][j--]);
		}
		j++;
		i--;
//		printf("\n");
		while(i>ctr)
		{
			printf(" %c ",a[i--][j]);
		}
		ctr++;
//		printf("\n");
		fflush(stdout);
	}



printf("\n");
printf("\n");





	//NORMaL ORDER PRINT

	for(i=0;i<size;printf("\n"),i++)
		for(j=0;j<size;j++)
			printf("  %c  ",*(*(a+i)+j));

}
