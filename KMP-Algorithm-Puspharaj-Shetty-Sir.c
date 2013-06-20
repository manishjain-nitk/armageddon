#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0,i=0,no=0; 
   computeLPSArray(pat, M, lps); 	
    
printf("Longest Proper Suffix is : ");
	for(i=0;i<M;i++)
	{
	printf("%d ",lps[i]);
	}
printf("\n");
	for(i=0;i<M;i++)
	{
		if(pat[i]!=txt[i])
		no=1;
	}
	if(no==0)
	{
	printf("Found pattern at index 0\n");
}
    
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
      if (j == M)
      {
        printf("Found pattern at index %d \n",i-j+1);
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
 

int main(int argc,char *argv[])
{
   printf("\nString  : %s\n",argv[1]);
   printf("Pattern : %s\n",argv[2]);
   KMPSearch(argv[2],argv[1]);
   return 0;
}
