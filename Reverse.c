#include<stdio.h>
#include<string.h>
printReverse(char *s,int len)
{
	printf("\nReversed string is : ");
	auxPrintReverse(s,len-1);
	printf("\n");
}
auxPrintReverse(char *s,int lastIndex)
{
	int i,k;
	for(i=lastIndex;i>-1 && s[i]!=' ';i--);
	for(k=i+1;s[k]!='\0' && k<=lastIndex;k++)
		printf("%c",s[k]);
	printf(" ");
	if(i>0)
		auxPrintReverse(s,i-1);
}
int main()
{
	char s[100];
	printf("\nEnter the string : ");
	gets(s);
	printReverse(s,strlen(s));
	return 0;
}
