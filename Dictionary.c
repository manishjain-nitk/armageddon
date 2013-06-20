#include<stdio.h>
#include<string.h>
#include<malloc.h>
void check(char *str,char **s,int start,char *matched,int dicLength)
{
	int i,j,f=0,mc=0;
	for(i=0;i<dicLength;i++)
		if(s[i][0]==str[start])
		{
			f=0;
			for(j=1;s[i][j]!='\0';j++)
			{	if(s[i][j]!=str[start+j])
				{f=1;break;}
			}
			if(!f)
			{	
				char *match;
				match=(char *)malloc(100);
				strcpy(match,matched);
				strcat(match,s[i]);
				strcat(match," ");
				if(str[start+j]=='\0') printf("\n%s\n",match);
				else check(str,s,start+j,match,dicLength);
			}
			mc++;
		
		}
}
int main()
{
	char **s;
	char *str;
	char *matched;
	int n,i;
	s=(char **)malloc(sizeof(char *)*100);
	printf("Number of words in dictionary : ");
	scanf("%d",&n);
	for(i=0;i<n;i++,fflush(stdin))
	{
		s[i]=(char *)malloc(100);
		scanf("%s",s[i]);
		fflush(stdin);
	}
	str=(char *)malloc(100);
	matched=(char*)malloc(100);
	while(1)
	{
	printf("Enter search string : ");
	scanf("%s",str);
	matched[0]='\0';
	check(str,s,0,matched,n);
	}
}
