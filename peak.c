#include<stdio.h>
void main()
{
	char a[100];
	int prev,next,i;
	gets(a);
	prev=1;
	next=0;
	printf("\n\n");
	for(i=0;a[i+1]!='\0';i++)
	{
		next=(a[i]-48)>=(a[i+1]-48);
		if(i>0 && a[i]==a[i-1])
		    prev=!prev;
		if(prev && next )
		printf("%c",a[i]);
		prev=!next;
	}
	if(prev)
	{
		printf("%c",a[i]);
	}
}

