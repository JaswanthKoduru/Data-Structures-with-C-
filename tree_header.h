#include<iostream>
#include<stack>
using namespace std;

struct node{
	int value;
	node *left,*right;
	node(int k)
	{
		value = k;
		left = right = NULL;
	}
};

class tree{
	
	public:
				
		void inorder(node *root)
		{
			node *current = root;
			if(current == NULL)
				return;
			inorder(current->left);
			cout<<current->value<<" ";
			inorder(current->right);
		}
		
		void preorder(node *root)
		{
			node *current = root;
			if(current == NULL)
				return;
			cout<<current->value<<" ";
			preorder(current->left);
			preorder(current->right);
		}
		
		void postorder(node *root)
		{
			node *current = root;
			if(current == NULL)
				return;
			postorder(current->left);
			postorder(current->right);
			cout<<current->value<<" ";
		}
		
		int tree_size(node *root)
		{
			node *current = root;
			if(root == NULL)
				return 0;
			return 1+tree_size(current->left)+tree_size(current->right);
		}
		
		int tree_max(node *root)
		{
			node *current = root;
			if(root == NULL)
				return INT_MIN;
			return max(  current->value, max(tree_max(root->left),tree_max(root->right))  );
		}
		
		int tree_height(node *root)
		{
			node *current = root;
			if(root == NULL)
				return 0;
			return (1 + tree_height(current->left) +tree_height(current->right) );
		}
		
		void iterative_inorder(node *root)
		{
			if(root==NULL)
				return;
			
			stack <node*> stk;
			node *current = root;
			
			while(current!=NULL || stk.empty()==false )
			{
				while(current!= NULL)
				{
					stk.push(current);
					current = current->left;
				}
				current = stk.top();
				stk.pop();
				
				cout<<current->value<<" ";
				current = current->right;
			}
			
		}	
};

