#include<stdio.h>
int
main ()
{
  int i, j, r, c, count, k;
  float a[1000000] = { 0.0 }, x;
  scanf ("%d %d %f", &i, &j, &x);
  if (j <= i)
    {
      a[0] = x;
      printf ("\n\n");
      for (r = 0, count = 0, k = 1; r < i; k++, r++)
	{
	  for (c = 0; c <= r; c++)
	    {
	      x = a[count + c];
	      if (x > 1.0)
		{
		  x -= 1.0;
		  a[count + c] = 1.0;
		  a[count + c + k] += x / 2.0;
		  a[count + c + k + 1] += x / 2.0;
		}
	    }
	  count += k;
	}
      k = (i * (i - 1)) / 2 + j - 1;
      printf ("amount of water in %d column in %d row is : %f\n\n", j, i,
	      a[k]);
    }
  return 0;
}
