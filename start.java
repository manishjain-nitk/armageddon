//Run in first time, I am a java developer dude! :D
import java.util.Scanner;
class start
{

	start()
	{
		driver();
	}
	void driver()
	{
		int a;
		System.out.println("Welcome to the program on ArrayList : ");	
		System.out.println("Menu \n1.) Add at front \n2.) Remove from last \n3.) Remove from begining \n4.) Add at last \n5.) Find\n  ");
	Scanner s = new Scanner(System.in);
	a=s.nextInt();
	System.out.println("\nvalue is "+a);
	}
	public static void main(String args[])
	{
		new start();
	}	
}



