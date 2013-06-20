#include<stdio.h>
int
main ()
{
  int b[10][10],n, i, j, k, a[10][10];
  printf ("\nEnter the number of nodes: ");
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  printf ("\nEnter the distance between the host %d%d:", i + 1,
		  j + 1);
	  scanf ("%d", &a[i][j]);
	}
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	printf ("%d\t", a[i][j]);
      printf ("\n");
    }
  for (k = 0; k < n; k++)
    {
      for (i = 0; i < n; i++)
	{
	  for (j = 0; j < n; j++)
	    {
	      if (a[i][j] > a[i][k] + a[k][j])
		a[i][j] = a[i][k] + a[k][j];
	    }
	}
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  b[i][j] = a[i][j];
	  if (i == j)
	    b[i][j] = 0;
	}
    }
  printf ("\nThe output matrix is:\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	printf ("%d\t", b[i][j]);
      printf ("\n");
    }
  return 0;
}
