
#include <stdio.h>
//#include < conio.h>

void main()

{
      int a[10],bucket[10][20],b_count[10],bucket_num;
      int n,i,j,k,divisor,largest,digits,num,count;

  //    clrscr();

      printf("Enter the size of array: ");
      scanf("%d",&n);
      printf("\nEnter the elements of array:\n");
      for(i=0;i      {
        scanf("%d",&a[i]);
      }
      largest=a[0];
      for(i=0;i      {
        if(largest        {
          largest=a[i];
        }
      }
      num=largest;
      digits=0;
      while(num!=0)
      {
        num=num/10;
        digits=digits+1;
      }
      divisor=1;
      for(k=0;k      {
        for(i=0;i<10;i++)
        {
          b_count[i]=0;
          for(j=0;j<20;j++)
          {
            bucket[i][j]=0;
          }
        }
        for(i=0;i        {
          bucket_num=(a[i]/divisor)%10;
          bucket[bucket_num][b_count[bucket_num]]=a[i];
          b_count[bucket_num]=b_count[bucket_num]+1;
        }
        count=0;
        for(i=0;i<10;i++)
        {
          for(j=0;j          {
            a[count]=bucket[i][j];
            count++;
          }
        }
        divisor=divisor*10;
      }
      printf("\nAfter sorting the elements of array are:\n");
      for(i=0;i      {
        printf("%d ",a[i]);
      }
//      getch();
}

