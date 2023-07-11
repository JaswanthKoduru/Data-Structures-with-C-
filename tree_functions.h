#include<iostream>
#include<stack>
using namespace std;


struct tnode{
	int value;
	tnode *left,*right;
	tnode(int k)
	{
		value = k;
		left = right = NULL;
	}
};

class tree{
	
	public:
				
		void inorder(tnode *root)
		{
			tnode *current = root;
			if(current == NULL)
				return;
			inorder(current->left);
			cout<<current->value<<" ";
			inorder(current->right);
		}
		
		void preorder(tnode *root)
		{
			tnode *current = root;
			if(current == NULL)
				return;
			cout<<current->value<<" ";
			preorder(current->left);
			preorder(current->right);
		}
		
		void postorder(tnode *root)
		{
			tnode *current = root;
			if(current == NULL)
				return;
			postorder(current->left);
			postorder(current->right);
			cout<<current->value<<" ";
		}
		
		int tree_size(tnode *root)
		{
			tnode *current = root;
			if(root == NULL)
				return 0;
			return 1+tree_size(current->left)+tree_size(current->right);
		}
		
		int tree_max(tnode *root)
		{
			tnode *current = root;
			if(root == NULL)
				return INT_MIN;
			return max(  current->value, max(tree_max(root->left),tree_max(root->right))  );
		}
		
		int tree_height(tnode *root)
		{
			tnode *current = root;
			if(root == NULL)
				return 0;
			return (1 + tree_height(current->left) +tree_height(current->right) );
		}
		
		void iterative_inorder(tnode *root)
		{
			if(root==NULL)
				return;
			
			stack <tnode*> stk;
			tnode *current = root;
			
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

void tree_functions()
{
	cout<<"\n"
	"1)Inorder\n"
	"2)Preorder\n"
	"3)PostOrder\n"
	"4)Size of tree\n"
	"5)Maximum value\n"
	"6)Height of tree\n"
	"7)Iterative Inorder\n\n";
}
