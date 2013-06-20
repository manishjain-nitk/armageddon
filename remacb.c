#include<stdio.h>
void main()
{
	int i,cur,act;
	char a,b,c,str[100];
	gets(str);
	a='a';
	b='b';
	c='c';
	cur=0;
	act=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==b)
		{
			continue;
		}
		if(str[i]==a)
		{
			if(str[i+1]==c)
			{
				i++;
				continue;
			}
		}
		str[act]=str[i];
		act++;
		cur++;
	}
	str[act]='\0';
	printf("\n\n%s\n",str);
}
