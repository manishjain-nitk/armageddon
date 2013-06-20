#include<stdio.h>
#include<string.h>

void compute(int *pi,int len)
{
	int k,q;
	pi[0]=0;
	k=0;
	for(q=0;q<len;q++,printf("\n%d",pi[q]));
	for(q=1;q<len;q++)
	{
		while(k>0&&pi[k+1]!=pi[q])
			k=pi[k];
		if(pi[k+1]==pi[q])
			k++;
		pi[q]=k;
	}
	for(q=0;q<len;q++,printf("\n%d",pi[q]));
}







void kmp(char *a,char *b)
{
	int pi[1000],i,len;
	int k,q;
	printf("String : ");puts(a);
	puts("\n\nPattern : ");
	puts(b);
	for(i=0;i<strlen(b);i++,pi[i]=0);
//	compute(pi,strlen(b));
	len=strlen(b);
	pi[0]=0;
	k=0;
	for(q=0;q<len;q++,printf("\n%d",pi[q]));
	if(b[0]==b[1])
		pi[1]=1;
	for(q=2;q<len;q++)
	{
		while(k>0&&b[k+1]!=b[q])
			k=pi[k];
		if(b[k+1]==b[q])
			k++;
		pi[q]=k;
	}
	for(q=0;q<len;q++,printf("\n%d",pi[q]));
}
int main()
{
	char a[10000];
	char b[10000];
	gets(a);
	gets(b);
	kmp(a,b);
}
