import java.util.*;
class HashMap
{
	public static void main(String args[])
	{
	
		int i,n=5;
		Scanner sc= new Scanner(System.in);
		Set<String> s= new HashSet<String>();
			System.out.println("Enter Dictionary  : ");
		for(i=0;i<n;i++)
			s.add(sc.next());
		for(i=0;i<n;i++)
			System.out.println(s.getIndex(i));

	}
}
