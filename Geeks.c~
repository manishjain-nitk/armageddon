/*
   Complexity of this algorithm :
   a.) Finding length of all strings provided : O(|A|)+O(|B|)+O(|C|)
   b.) KMPSearch : At the max KMPSearch is invoked 4 times, which takes 2*(O(|A|+|C|)+2*(O(|B|+|C|)
   		   which can be called as O(max(|A|,|B|)+|C|)

	Giving a asymptotic complexity of O(max(|A|,|B|)+|C|),which is indeed much better than O(|A||B|)
   		  
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void computeLPSArray(char *pat, int M, int *lps);
int  KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int *lps = (int *)malloc(sizeof(int)*M);
	int j  = 0;
	computeLPSArray(pat, M, lps);
	int i = 0; 
	while(i < N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			return (i-j);
			j = lps[j-1];
		}


		else if(pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
	free(lps); 
	return -1;
}
void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0; 
	int i;
	lps[0] = 0;
	i = 1;
	while(i < M)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if( len != 0 )
			{
				len = lps[len-1];
			}
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
/*
 I use KMP Algorithm for string matching which would require O(m+n), where m=pattern length and n=text length.

 Now as A and B occurs in C we can find them and delete the pattern which has been identified from the text,
 so we proceed in following fashion :
 a.) find A in C if found delete it
 b.) find B in c 
 hence, we can say they are interleaved in C.
 */
int prefFirst(char *a,char *b,char *temp,int al,int bl,int cl)
{
	int i,resa=-1,index=0,resb=-1,k=-1;
	char c[100];
	strcpy(c,temp);
	if(al==0) resa=1;
	if(bl==0) resb=1;
	if(al>bl)//We decide which text to see first by comparing there lenght, coz there is a possiblity that small text deletion may disturb the long text.
	{
		resa=index=KMPSearch(a,c);//search for element A
		if(index==-1)
			index=0;//if not found set it again to zero
		if(resb==-1)
			for(i=index,k=al+index;c[k]!=0;i++,k++)
				c[i]=c[k];//shifting of elements, so as to give an effect as if A never existed in the text
		c[i]='\0';
		resb=KMPSearch(b,c);//search the element B
	}
	else
	{
		resb=index=KMPSearch(b,c);
		if(index==-1)
			index=0;
		if(resa==-1)
			for(i=index,k=bl+index;c[k]!=0;i++,k++)
				c[i]=c[k];
		c[i]=0;
		resa=KMPSearch(a,c);
	}
	return ((resa!=-1) && (resb!=-1));
}

int main(int argc,char *argv[])
{

	int al=0,bl=0,resa=-1,resb=-1,index=-1,index2=-1;
	char a[100],b[100],c[100];
	int i,cl;
	while(1)
	{
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		al=strlen(a);
		if(al==0)resa=1;
		bl=strlen(b);
		if(bl==0)resb=1;
		cl=strlen(c);
		if(cl==0 && a==0 && b==0)
			return (printf("\nInterleaved\n")-13);
		if( prefFirst(a,b,c,al,bl,cl) || prefFirst(b,a,c,bl,al,cl))//if either of them becomes true its Interleaved
		{
			printf("\nInterleaved\n");
		}
		else
		{
			printf("\nNot Interleaved\n");
		}
	}
	return 0;
}
