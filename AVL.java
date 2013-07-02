/*
 Height balancing is all required here.
 */
import java.util.*;
import java.util.concurrent.*;
class TreeNode
{
	int data;
	TreeNode right,left;
	public TreeNode(int y)
	{
	 data=y;
	 right=left=null;
	}
}
class AVLTree
{
	TreeNode root;
	public AVLTree()
	{
		root=null;
	}
	public void  avlInsert(int data)
	{

		if(root==null)
		{
			root = new TreeNode(data);
			return;
		}
		if(data <= root.data)
		auxavlInsert(root,root,data);
		else
		auxavlInsert(root,root,data);
	}

	public TreeNode auxavlInsert(TreeNode parent,TreeNode root,int x)
	{
	
		TreeNode first,second;
		int lh,rh;		
		if(x > root.data)
		{
			if(root.right!=null)
			{
				first=root.right;
				second=auxavlInsert(root,root.right,x);
			}
			else
			{
				root.right= new TreeNode(x);
				return root.right;
			}


		}
		else
		{
			
			if(root.left!=null)
			{
				first=root.left;
				second=auxavlInsert(root,root.left,x);
			}
			else
			{
				root.left = new TreeNode(x);
				return root.left;
			}
		}
		if(root.left!=null)
		lh=height(root.left);
		else
		lh=-1;
		if(root.right!=null)
		rh=height(root.right);
		else
		rh=-1;
		if( (lh - rh) > 1 || (rh-lh) > 1)
		{
			balance(parent,root,first,second);
		}
		return first;
	}
	private int max(int a,int b)
	{
		if(a>b)
			return a;
		else
			return b;
	}
	public int height(TreeNode root)
	{
		int lh=0,rh=0;
		if (root==null) return -1;
		lh=1+height(root.left);
		rh=1+height(root.right);
		return max(lh,rh);
	}
	public void display()
	{
		System.out.println("Here's the tree preorder : \n");
		preOrder(root);
		System.out.println();
		System.out.println("Here's the tree inorder : \n");
		inOrder(root);
		System.out.println();
		System.out.println("Here's the tree postorder : \n");
		postOrder(root);
		System.out.println();

	}
	public void preOrder(TreeNode root)
	{
		if(root==null) return;
		System.out.print(" "+root.data+" ");
		preOrder(root.left);
		preOrder(root.right);
	}
	public void postOrder(TreeNode root)
	{
		if(root==null) return;
		postOrder(root.left);
		postOrder(root.right);
		System.out.print(" "+root.data+" ");
	}
	public void inOrder(TreeNode root)
	{
		if(root==null) return;
		inOrder(root.left);
		System.out.print(" "+root.data+" ");
		inOrder(root.right);
	}
	private void balance(TreeNode parent,TreeNode root,TreeNode first,TreeNode second)
	{
		if(root.left!=null && root.left.left!=null)
		if(second==root.left.left)
		{
			singleRotateRight(parent,root,first,second);
		}
		if(root.right!=null && root.right.right!=null)
		if(second==root.right.right)
		{
			singleRotateLeft(parent,root,first,second);
		}
		if(root.right!=null && root.right.left!=null)
		if(second==root.right.left)
		{
			doubleRotateRight(parent,root,first,second);
		}
		if(root.left!=null && root.left.right!=null)
		if(second==root.left.right)
		{
			doubleRotateLeft(parent,root,first,second);
		}
		
	}
		
	private void singleRotateLeft(TreeNode parent,TreeNode root,TreeNode first,TreeNode second)
	{
		if (parent==root)
		{
			this.root=first;
		}
		else if(parent.left==root)
		{
			parent.left=first;
		}
		else
		{
			parent.right=first;
		}
		root.right=first.left;
		first.left=root;
		
	}
	private void singleRotateRight(TreeNode parent,TreeNode root,TreeNode first,TreeNode second)
	{
			
		if(parent==root)
		{
			this.root=first;
		}
		else if(parent.left==root)
		{
			parent.left=first;
		}
		else
		{
			parent.right=first;
		}
		root.left=first.right;
		first.right=root;
	}
	private void doubleRotateLeft(TreeNode parent,TreeNode root,TreeNode first,TreeNode second)
	{	
		first.right=second.left;
		root.left=second;
		second.left=first;
		singleRotateRight(parent,root,second,first);
	}
	private void doubleRotateRight(TreeNode parent,TreeNode root,TreeNode first,TreeNode second)
	{
		first.left=second.right;
		root.right=second;
		second.right=first;
		singleRotateLeft(parent,root,second,first);
	}

}
class AVL
{
	public static void main(String args[])
	{
		Scanner sc= new Scanner(System.in);
		int x;
		int i=0;
		AVLTree avl = new AVLTree();
		while(i++<10){
			x=sc.nextInt();
		avl.avlInsert(x);}
		avl.display();
	}
}
