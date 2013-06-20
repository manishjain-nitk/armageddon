import java.util.*;
import java.util.concurrent.*;

class TreeNode
{
	Object data;
	TreeNode left,right;
	public TreeNode()
	{
		data=new Object();
		data=left=right=null;
	}
	public TreeNode(Object value)
	{
		data=new Object();
		data=value;
		left=right=null;
	}
	public Object getData()
	{
		return data;
	}
}

class CompleteBinaryTree
{
	private TreeNode root;
	private int size;
	public  CompleteBinaryTree()
	{
		root=null;
		size=0;
	}
	public boolean createRandom(int a[])
	{

		root=null;
		root=auxCreateRandom(a,0,a.length-1);
		return (root!=null);	
	}
	private int getInRangeRandom(int l,int r)
	{
		Random rn = new Random();
		return (l+rn.nextInt(r-l+1));
	}
	private TreeNode auxCreateRandom(int a[],int l, int r)
	{
		if(l<=r)
		{
			int randomIndex=getInRangeRandom(l,r);
			TreeNode root = new TreeNode(a[randomIndex]);
			root.left=auxCreateRandom(a,l,randomIndex-1);
			root.right=auxCreateRandom(a,randomIndex+1,r);
			return root;
		}
		return null;
	}
	public boolean add(Object value)
	{
		if(root==null)
		{
			root = new TreeNode(value);
			return true;
		}
		else
		{
			TreeNode temp,prev;
			Queue<TreeNode> q = new ConcurrentLinkedQueue<TreeNode>();
			q.add(root);
			while(!q.isEmpty())
			{
				temp=(TreeNode)q.remove();
				if(temp.left==null)
				{	
					temp.left= new TreeNode(value);
					size++;
					return true;
				}
				else if (temp.right==null)
				{	
					temp.right= new TreeNode(value);
					size++;
					return true;
				}
				else
				{
					q.add(temp.left);
					q.add(temp.right);
				}

			}
		}
		return false;
	}

	public void preOrder()

	{
		auxPreOrder(root);
	}

	private void auxPreOrder(TreeNode root)
	{
		if(root!=null)
		{
			System.out.print(" "+root.data+" ");
			auxPreOrder(root.left);
			auxPreOrder(root.right);
		}
	}
	public void inOrder()
	{
		auxInOrder(root);
	}
	private void auxInOrder(TreeNode root)
	{
		if(root!=null)
		{
			auxInOrder(root.left);
			System.out.println(" "+root.data+" ");
			auxInOrder(root.right);

		}
	}

	public void revLevelOrder()
	{
		Queue<TreeNode> q = new ConcurrentLinkedQueue<TreeNode>();
		Stack<Object> s = new Stack<Object>();
		TreeNode temp;
		if(root==null)
			return;
		q.add(root);
		s.add(root.data);
		while(!q.isEmpty())
		{
			temp=q.remove();
			if(temp.right!=null)
			{
				s.add(temp.right.data);
				q.add(temp.right);
			}

			if(temp.left!=null)
			{
				s.add(temp.left.data);
				q.add(temp.left);
			}
		}
		while(!s.isEmpty())
		{
			System.out.print(" "+s.pop()+" ");
		}
	}


	public TreeNode	find(Object value)
	{
		if(root==null) return null;
		TreeNode temp;
		Queue<TreeNode> q = new  ConcurrentLinkedQueue<TreeNode>();
		q.add(root);
		while(!q.isEmpty())
		{
			temp=q.remove();
			if(temp.data.equals(value))
				return temp;
			if(temp.left!=null)
				q.add(temp.left);
			if(temp.right!=null)
				q.add(temp.right);
		}
		return null;
	}

	public Object height()
	{
		return auxHeight(root);
	}
	private int  max(int a,int b)
	{
		if(a>b)
			return a;
		else 	
			return b;
	}
	private int  auxHeight(TreeNode root)
	{
		if(root==null) return -1;
		int lh,rh;
		lh=auxHeight(root.left)+1;
		rh=auxHeight(root.right)+1;
		return max(rh,lh);
	}
	public TreeNode LCA(int a, int b)
		
	{
	 return	auxLCA(root,a,b);
	}
	
	public TreeNode auxLCA(TreeNode root,int a,int b)
	{
		TreeNode right=null,left=null;
		if(root==null) return root;
		if(root.data.equals(a) || root.data.equals(b) ) return root;
		left=auxLCA(root.left,a,b);
		right=auxLCA(root.right,a,b);
		if (left!=null && right!=null)
			return root;
		if(left!=null)	return left;
		if(right!=null) return right;
		return null;
	}

	public createAVLTree()
	{
		
	}





}


class JavaTree
{

	public static void main(String args[])
	{
		CompleteBinaryTree tree = new CompleteBinaryTree();
		Scanner sc = new Scanner(System.in);
		Object value;
		int lca1,lca2;
		int a[]=new int[10];
		int i=0;
		do
		{
			value =sc.nextInt();
			if(!value.equals(0))
				tree.add(value);
		}while(!value.equals(0));
		while(1)
		{
			System.out.println("Enter your choice : \n1Inorder\n2InorderRecursive\n3Preorder\n4PreorderRecursive\n5Postorder\n6PostOrderRecursive\n7LCA\n8RandomBinaryTree\n9InPlaceTraversal\n10LevelOrderTraversal\n11ReverseLevelOrder");
			switch (n)
			{
				case 1
			}
		}
		System.out.println();
		System.out.print("Inorder : ");
		tree.inOrder();
		System.out.println();
		System.out.print("Reverse Level Order : ");
		tree.revLevelOrder();
		System.out.println();
		System.out.print("Enter the element you want to find : ");
		value=sc.nextInt();
		if((tree.find(value)!=null))
			value = true;
		else
			value=false;
		System.out.println("Find status for the element : "+ value);
		System.out.println();
		System.out.println("Find LCA of ");
		lca1=sc.nextInt();
		lca2=sc.nextInt();
		System.out.println("LCA of 2 and 3 is "+ tree.LCA(lca1,lca2).getData());
		/*do
		{
			value =sc.nextInt();
			if(!value.equals(0))
			{
				a[i]=(int)(Integer.parseInt(value.toString()));
				i++;
			}
		}while(i<10);
		tree.createRandom(a);
		System.out.println();*/
		System.out.print("Inorder : ");
		tree.inOrder();
		System.out.println();
		System.out.println("Height of the tree is : "+ tree.height());
	}

}
