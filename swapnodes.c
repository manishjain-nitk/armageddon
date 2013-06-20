#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next;
};

struct node* createNode(struct node *temp)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&new->data);
	new->next=NULL;
	temp->next=new;
	return new;
}

void createList(struct node* head)
{
	int n;
	struct node *temp;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	temp=head;
	while(n--)
		temp=createNode(temp);
}


void displayList(struct node* head)
{
	struct node* temp=head->next;
	printf("\n");
	while(temp)
	{
		printf("  %d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void swapNodes(struct node *head)
{
	struct node *temp=head->next, *temp2,*temp3;
	temp2=head;
	printf("Swapped nodes : \n");
	while(temp && temp->next)
	{
		temp2->next=temp->next;
		temp->next=temp->next->next;
		temp2->next->next=temp;
		temp2=temp2->next->next;
		temp=temp->next;
	}
}


int main()
{
	struct node *head;
	head=(struct node *) malloc(sizeof(struct node));
	head->data=(int)NULL;
	head->next=NULL;
	createList(head);
	displayList(head);
	swapNodes(head);
	displayList(head);
	return 0;
}
