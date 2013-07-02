import java.util.*;
import java.util.concurrent.*;

class ReverseWords 
{
	public static  void printReverse(String  s)
	{
		
		auxPrintReverse(s.toCharArray(),s.toCharArray().length-1);
	}
	public	static  void auxPrintReverse(char a[100],int index)
	{
		int i,k;
		for(i=index;(i>-1)&&a[i]!=' ';i--);
		for(k=i+1;k<=index;k++)
			System.out.print(a[k]);
		if(i!=0)
			auxPrintReverse(a,i);
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String s = new String();
		s=sc.next();
		printReverse(s);
	}
}


