#include<malloc.h>
#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *child;
};

template <class T>
class queue{

	private: int front;
		 int rear,no;
		 T q[100];
	public: 
		 queue()
		 {
			 front=rear=-1;
			 no=0;
		 }
		 void insert(T data)
		 {
			 if(no==100)return printf("\nNot enough space\n");
			 if(!no)
				 front=rear=0;
			 else
				 ++rear;
			 q[rear]=data;
			 no++;
		 }
		 T remove()
		 {
			if(no==0) return printf("\nNo Elements\n");
			else 
				no--;
			return (q[front++]);
				
		 }
		 int  getElements()
		 {
		 	return no;
		 }
		 void emptyq()
		 {
		 	queue();
		 }
		 int isempty()
		 {
			return !no;
		 }
};


class LinkedList()
{
	struct node* head;
	public :
	LinkedList()
	{
		size=0;
		head=new(struct node);
		head->data=NULL;
		head->next=NULL;
		cout<<"List initialized";
	}
	addNode(struct node *parent)
	{
		struct node *temp;
		temp=new (struct node);
		cout<<"Enter node data : ";
		cin>>temp->data;
		cout<<"Child?? : ";
		parent=temp;
		while(child)
		{
			
			child--;
		}

	}
	}
}
















int main()
{
	queue<struct node *> a;
	struct node *head[100];
	a.remove();
	head[0]=new (struct node);
	head[2]=new (struct node);
	head[1]=new (struct node);
	head[3]=new (struct node);
	head[0]->data=2;
	head[1]->data=20;
	head[2]->data=22;
	head[3]->data=232;
	a.insert(head[0]);
	a.insert(head[2]);
	a.insert(head[3]);
	a.insert(head[1]);
	cout<<"\nqueue empty : "<<a.isempty();
	cout<<"\nval removed : "<<(a.remove())->data;
	cout<<"\nval removed : "<<(a.remove())->data;
	cout<<"\nqueue empty : "<<a.isempty()<<endl;
}
