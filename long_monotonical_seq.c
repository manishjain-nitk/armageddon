#include<stdio.h>

int main()
{
	int a[]={1,4,8,2,5 3,4,2,5,66,6,7,3,6,5,3,2,65,4,3,2,3,65,6,4,3,3,5,7,3,4,6};
	int i,top=0,j,k,l,s[10]={0},max=0;
	for(i=1;i<9;i++)
	{
		if(a[i]>=a[top])
			a[++top]=a[i];
		else
		{
			if(top>max-1){
			for(j=0;j<=top;j++)
			s[j]=a[j];
			max=j;}
			while(a[i]<a[top])
				top--;
			a[++top]=a[i];
		}
	}
	
			if(top>max-1){
			for(j=0;j<=top;j++)
			s[j]=a[j];
			max=j;}

		printf("maximum list is : \n");
		for(i=0;i<max;printf(" %d ",s[i]),i++);
		printf("\n");
	

}
