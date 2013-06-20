#include<stdio.h>

struct mydef
{
	private : int x;
	public : 
	void insert()
	{
		printf("enter the value of x : ");
		scanf("%d",&x);
	}
	void show()
	{
		printf("the value of x is %d %n",x,&x);
		
		printf("the value of x is %d",x);
	}
};

int main()
{
	struct mydef a;
	a.insert();
	a.show();
//	a.x=2;
}


