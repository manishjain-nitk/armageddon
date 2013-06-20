import java.util.*;
import java.util.concurrent.*;

class TreeNodeGeneric
{
	public Object data;
	public TreeNodeGeneric sibling;
	public TreeNodeGeneric child;
	public TreeNodeGeneric(Object value)
	{
		this.data=value;
		this.sibling=null;
		this.child=null;
	}
}

class CreateTree
{
	TreeNodeGeneric root,child;
	public CreateTree()
	{
		root=null;
	}
	public boolean addTree(Object value,Object child_value)
	{
		if(root==null)
		{
			root=new TreeNodeGeneric(value);
			child=new TreeNodeGeneric(child_value);
			root.child=child;
			return true;
		}
		else
		{
			TreeNodeGeneric getNode=genericSearch(value);
			if(getNode!=null)
			{
				TreeNodeGeneric prev,temp;
				prev=getNode;
				temp=getNode.child;
				if(temp==null)
				{	prev.child= new TreeNodeGeneric(child_value);
					return true;
				}
					while(temp!=null)
				{
					prev=temp;
					temp=temp.sibling;
				}
				prev.sibling = new TreeNodeGeneric(child_value);
				return true;
			}
			else
			{
				TreeNodeGeneric temp,prev;
				prev=root;
				temp=root.sibling;
				while(temp!=null)
				{	prev=temp;
					temp=temp.sibling;
				}
				prev.sibling=new TreeNodeGeneric(value);
				prev.sibling.child = new TreeNodeGeneric(child_value);
				return true;
			}
			

		}

	}

	private TreeNodeGeneric genericSearch(Object value)
	{
		TreeNodeGeneric temp;
		temp=root;
		Stack<TreeNodeGeneric> s = new Stack<TreeNodeGeneric>();
		s.add(null);
		while(temp!=null)
		{
		while(temp!=null)
		{
			if(temp.data.equals(value))
				return temp;
			s.add(temp);
			temp=temp.child;
		}
		temp=s.pop().sibling;
		}
		return null;
	}






	public void displayTreeGeneric()
	{
		TreeNodeGeneric temp;
		String var=new String(""); 
		temp=root;
		Stack<TreeNodeGeneric> s = new Stack<TreeNodeGeneric>();
		s.add(null);
		while(!s.isEmpty())
		{
		while(temp!=null)
		{
			
			System.out.println(var+"-->"+temp.data);
			s.add(temp);
			temp=temp.child;
			var=var.concat("  |"); 
		}
		
		if((temp=s.pop())!=null)
			{
				temp=temp.sibling;
				var=var.substring(3);
			}
		}

	}
}


class CustomTree
{
	public static void main(String args[])
	{
		String s = new String();
		CreateTree tree = new CreateTree();
		Scanner sc = new Scanner (System.in);
		Object source=new Object();
		Object dest=new Object();
		int choice=1;
		while(choice==1)
		{
				source=sc.next();
				dest=sc.next();
				tree.addTree(source,dest);
				choice=sc.nextInt();
		}
		tree.displayTreeGeneric();
	}
}
