#include<stdio.h>
int a[2000000], n;
void
removea (int i)
{
  int k;
  for (k = i; k < n; k++)
    {
      a[k] = a[k + 1];
    }
}

int
main ()
{
  int b[2000000];
  int i;
  printf ("no of soldiers : ");
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      a[i] = (n - i);
    }
  for (i = 0; i < n; i++)
    scanf ("%d", b + i);
  for (i = n - 1; i > -1; i--)
    {
      b[i] = (a[b[i]]);
      removea (b[i]);
    }
  for (i = 0; i < n; i++)
    printf ("%d", b[i]);
}
