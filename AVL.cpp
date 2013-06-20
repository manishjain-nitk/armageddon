#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


template <class T>
class TreeNode
{
	public:
	T data;
	TreeNode *left;
	TreeNode *right;
};



template  <class T>
class AVLTree
{
	private :
		TreeNode<T> *root;	
	public : 
		void setValue(T value)
		{
			root = new TreeNode<T>;
			root->data=value;
		}
		T getValue()
		{
			return root->data;
		}

 
};
int  main()
{
	AVLTree<int> tree;
	tree.setValue(5);
	cout<<tree.getValue();
	return 0;
}
