// Hash Table Implementation in C
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INIT_SIZE 3
#define LOAD_FACTOR 2

typedef enum {FALSE,TRUE} boolean;

struct listNode
{
	int data;
	struct listNode *next;
};

struct hashTable
{
	struct listNode **arr;
	int nob;
	int noe;
};

struct hashTable * createHash()
{
	int i;
	struct hashTable *htbl= malloc(sizeof(struct hashTable));
	htbl->noe=0;
	htbl->nob=INIT_SIZE;
	htbl->arr=malloc(INIT_SIZE * sizeof(struct listNode *));
	for(i=0;i<INIT_SIZE;i++)
	{
		htbl->arr[i]=calloc(1,sizeof(struct listNode));
		htbl->arr[i]->data=-1;
		htbl->arr[i]->next=NULL;
	}
	return htbl;
}

int hash(int data,int nob)
{
	return data%nob;
}

boolean listInsert(struct listNode *head,int data)
{
	struct listNode *temp,*prev,*newNode;
	newNode=(struct listNode *)malloc(sizeof(struct listNode));
	newNode->data=data;
	temp=head->next;
	prev=head;
	while(temp!=NULL && temp->data < data)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		newNode->next=NULL;
	else
		newNode->next=prev->next;
	prev->next=newNode;
	return TRUE;
}

void rehash(struct hashTable *htbl)
{
	int i;
	struct listNode *temp,*cur;
	struct listNode **newArray=malloc(htbl->nob*2*sizeof(struct listNode *));

	for(i=0;i<(htbl->nob*2);i++)
	{
		newArray[i]=calloc(1,sizeof(struct listNode));
		newArray[i]->data=-1;
		newArray[i]->next=NULL;
	}
	for(i=0;i<(htbl->nob);i++)
	{
		for(cur=htbl->arr[i]->next;cur!=NULL;cur=cur->next)
		{
			int pos=hash(cur->data,htbl->nob*2);
			listInsert(newArray[pos],cur->data);
		}
		free(htbl->arr[i]);	
	}
	free(htbl->arr);
	htbl->arr=newArray;
	htbl->nob=2*htbl->nob;
}

boolean add (struct hashTable *htbl,int data)
{
	if(search(htbl,data))
		return printf("\nData Already Exists!\n");
	if((htbl->noe/htbl->nob)==LOAD_FACTOR)
		rehash(htbl);
	int pos=hash(data,htbl->nob);
	boolean res=listInsert(htbl->arr[pos],data);
	if(res)
	{
		htbl->noe++;
	}
	return res;
}


display(struct hashTable *htbl)
{

	int i;
	struct listNode *temp;
	for(i=0;i<htbl->nob;i++)
	{
		temp=(htbl->arr[i])->next;
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf(" | ");
	}
	printf("\n");
}

int search(struct hashTable *htbl,int data)
{

	int i;
	struct listNode *temp;
	for(i=0;i<htbl->nob;i++)
	{
		temp=(htbl->arr[i])->next;
		while(temp!=NULL)
		{
			if(temp->data==data) return 1;
			temp=temp->next;
		}

	}
	return 0;
}

displayStruct(struct hashTable *htbl)
{
printf("\nStructure contents are : \n\nhtbl->nob %d\n\nhtbl->noe %d\n",htbl->nob,htbl->noe);
}

int main()
{	
	char ch;
	int val;
	struct hashTable *htbl;
	htbl=createHash();
	while(1)
	{
	printf("\n\nadd/display(1/2)");
	scanf("%c",&ch);
	switch(ch)
	{
		case '1' : 
			scanf("%d",&val);
			add(htbl,val);
			displayStruct(htbl);
			break;
		case '2' :
			
			display(htbl);
			break;
		case '3' : exit(0);
	}}
}
