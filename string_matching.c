#include<stdio.h>

char * match(char *a,char* b)
{
	if(*a=='\0' && *b=='\0')
		return "MATCH";
	if (*b == '*' && *(b+1) != '\0' && *a == '\0')
	        return "NO MATCH";
	if (*b == '?' || *b == *a)
	          return match(b+1,a+1);
	if (*b == '*')
	        return match(b+1, a) || match(b, a+1);
	return "NO MATCH";
	
}
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	printf("Output : \n\n%s",match(a,b));
}
