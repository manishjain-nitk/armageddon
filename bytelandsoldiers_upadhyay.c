#include <stdio.h>
#include <malloc.h>

#define BUF 4096

typedef struct node
{
  int index;			//origninal index of node
  int lc;			//no. of nodes in left subtree 
  struct node *left, *right;
} node;



char ibuf[BUF];
int ipt = BUF;

int
readInt ()
{
  int n;
  while (ipt < BUF && ibuf[ipt] < '0')
    ipt++;
  if (ipt == BUF)
    {
      fread (ibuf, 1, BUF, stdin);
      ipt = 0;
      while (ipt < BUF && ibuf[ipt] < '0')
	ipt++;
    }
  n = 0;
  while (ipt < BUF && ibuf[ipt] >= '0')
    n = (n * 10) + (ibuf[ipt++] - '0');
  if (ipt == BUF)
    {
      fread (ibuf, 1, BUF, stdin);
      ipt = 0;
      while (ipt < BUF && ibuf[ipt] >= '0')
	n = (n * 10) + (ibuf[ipt++] - '0');
    }
  return n;
}

void
writeInt (int n)
{
  char ch = '0';
  if (n == 0)
    fwrite (&ch, 1, 1, stdout);

  while (n)
    {
      ch = '0' + (n % 10);
      n /= 10;
    }
}




void
insert (node * root, int index, int rank)
{
  int base_rank = 0;


  while (1)
    {
      if (rank > base_rank + root->lc)
	{
	  if (root->right)
	    {
	      base_rank = base_rank + 1 + root->lc;
	      root = root->right;
	    }
	  else
	    {
	      root->right = (node *) malloc (sizeof (node));
	      root = root->right;
	      root->left = root->right = NULL;
	      root->lc = 0;
	      root->index = index;
	      return;
	    }
	}
      else
	{
	  if (root->left)
	    {
	      root->lc += 1;
	      root = root->left;
	    }
	  else
	    {
	      root->left = (node *) malloc (sizeof (node));
	      root->lc += 1;
	      root = root->left;
	      root->left = root->right = NULL;
	      root->lc = 0;
	      root->index = index;
	      return;
	    }
	}
    }
}

void
store_new_ranks (node * root, int base_rank, int *shift)
{
  if (root->left)
    store_new_ranks (root->left, base_rank, shift);


  shift[root->index] = base_rank + root->lc;

  if (root->right)
    store_new_ranks (root->right, base_rank + 1 + root->lc, shift);
}


int
main ()
{
  int i, j, n, *shift, t;


  node *root;

  char ch2 = ' ';

  t = readInt ();
  for (j = 0; j < t; j++)
    {
      n = readInt ();
      shift = (int *) malloc (sizeof (int) * n);

      root = (node *) malloc (sizeof (node));
      root->lc = 0;
      root->index = 0;
      root->left = root->right = NULL;
      shift[0] = readInt ();

      for (i = 1; i < n; i++)
	{
	  shift[i] = readInt ();
	  insert (root, i, i - shift[i]);
	}


      store_new_ranks (root, 1, shift);

      for (i = 0; i < n; i++)
	{
	  printf ("%d ", shift[i]);
	}
      printf ("\n");
    }
  return 0;
}
