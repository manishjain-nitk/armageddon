#include<iostream>
#include<cstdio>
using namespace std;
class base
{
	int a;
	public :
	base()
	{
		printf("base constructor called\n");
	}
	~base()
	{
		printf("base destructor called\n");
	}

};
class derived : public  base
{ 
	private :
	int b;
	int  entra()
	{
		printf("kancham");
	}
	public:
	derived()
	{
		printf("derived constructor called\n");
	}
	~derived()
	{
		printf("derived destructor called\n");
	}

};

int main()
{
	base *p;
	p = new derived;
	p->entra();
	delete p;
	return 0;
}
