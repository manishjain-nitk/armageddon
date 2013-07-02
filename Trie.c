#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
struct TrieNode
{
	int isWord;
	struct TrieNode* arr[26];
};
struct TrieNode * makeNode(struct TrieNode* root,int index)
{
	int i;
	root->arr[index]=(struct TrieNode *)malloc(sizeof(struct TrieNode));
	for(i=0;i<26;i++)
	{
		root->arr[index]->arr[i]=NULL;
	}
	return root->arr[index];
}

void  addTrie(char a[],struct TrieNode* start)
{
	struct TrieNode* root=start;
	int i;
	for(i=0;a[i];i++)
	{
		if(root->arr[(a[i]-97)]==NULL)
		{
			root=makeNode(root,a[i]-97);
		}
		else
		{
			root=root->arr[(a[i]-97)];
		}
	}
	root->isWord=1;

}

void  printAll(struct TrieNode* root,char prefix[100],int len)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(root->arr[i]!=NULL)
		{
			char temp_pre[100];
			strcpy(temp_pre,prefix);
			temp_pre[len]=i+97;
			temp_pre[len+1]=0;
			printAll(root->arr[i],temp_pre,len+1);
		}
	}
	if(root->isWord)
		printf("\n%s\n",prefix);

}
void prefixSearch(char a[],struct TrieNode* start)
{
	struct TrieNode* root=start;
	int i,n=0;
	char text[100];
	text[n]=0;
	for(i=0;a[i];i++)
	{
		root=root->arr[a[i]-97];
		if(root==NULL)
		{
			printf("\nNo string with this prefix\n");
			return;
		}	
		else
		{
			text[n++]=a[i];
			text[n]=0;
		}
	}
	printAll(root,text,n);
}
int main()
{
	int i;
	struct TrieNode* root;
	char a[100];
	root=(struct TrieNode *)malloc(sizeof(struct TrieNode));
	root->isWord=0;
	for(i=0;i<26;i++)
	{
		root->arr[i]=NULL;
	}
	i=0;
	while(1)
	{
		scanf("\n%s",a);	
		addTrie(a,root);
	}
		printf("\nSearch Now\n");
	while(1)
	{
		a[0]=0;
		scanf("\n%s",a);
		printf("\n------\n");
		prefixSearch(a,root);
		printf("\n------\n");
	}
}
