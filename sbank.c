#include<stdio.h>
#include<string.h>
unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5381;
        int c;
        while (c = *str++)
           hash = ((hash << 5) + hash) + c;
        return hash;
}

int main()
{
	char a[100000][35];
	unsigned long int h[100000];
	char x;
	int n[1000000],s[100000];
	int i,j,k,l,f,hn=0,nos=0;
	scanf("%d",&nos);	
	while(nos--)
	{
	i=j=k=l=f=hn=0;
	scanf("%d",&l);
	x=getchar();
	for(i=0;i<l;i++)
	{
		
		char temp[35];
		fflush(stdin);
		gets(a[i]);//,33,stdin);
		strcpy(temp,a[i]);
		for(j=3;j<11;j++)
		{
		temp[j-1]=temp[j];
		}
		for(j=12;j<16;j++)
		{
		temp[j-2]=temp[j];
		}
		for(j=17;j<21;j++)
		{
		temp[j-3]=temp[j];
		}
		for(j=22;j<26;j++)
		{
		temp[j-4]=temp[j];
		}
		for(j=27;j<31;j++)
		{
		temp[j-5]=temp[j];
		}
		temp[26]='\0';//		printf("%s\n",a[i]);
		k=hash(temp);
		f=0;
		for(j=0;j<hn;j++)
		{
				if(k==h[j])
				{
					n[j]++;
					f=1;
					break;
				}
		}
		if(!f)
		{
			h[hn]=k;
			n[hn]=1;
			s[hn]=i;
			hn++;
		}
	
	}
	for(i=0;i<hn;i++)
	{
		printf("\n%s %d",a[s[i]],n[i]);
	}
	printf("\n");
	}
}
