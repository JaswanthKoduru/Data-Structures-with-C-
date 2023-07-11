#include<iostream>
using namespace std;

struct bnode{
	int value;
	bnode *left,*right;
	bnode(int k)
	{
		value = k;
		left=right=NULL;
	}
};

class bst{
	private:
		int result;
	public:
		
		bnode* getsuccessor(bnode* current)
		{
			current = current->right;
			while(current->left!=NULL && current!=NULL)
				current = current->left;
			return current;
		}
		
		void inorder(bnode *root)
		{
			bnode *current = root;
			if(current == NULL)
				return;
			inorder(current->left);
			cout<<current->value<<" ";
			inorder(current->right);
		}
		
		bool recursive_search(bnode* root, int x)
		{
			if(root==NULL)
				return false; 
			if(x == root->value)
				return true;
			else if(root->value > x)
				recursive_search(root->left,x);
			else if(root->value < x)
				recursive_search(root->right,x);		
		}
		
		bool iterative_search(bnode* root, int x)
		{
			while(root != NULL)
			{
				if(root->value == x)
					return true;
				else if( x > root->value )
					return iterative_search(root->right,x);	
				else if( x < root->value )
					return iterative_search(root->left,x);	
			}
			return false;
		}
		
		bnode* recursive_insert(bnode* root, int x)
		{
			if(root == NULL)
				root = new bnode(x);
				
			else if( x > root->value )
				root->right = recursive_insert(root->right,x);

			else if( x < root->value )
				root->left = recursive_insert(root->left,x);
				
			return root;
		}
		
		bnode* Iterative_insert(bnode* root, int x)
		{
			bnode* temp = new bnode(x);
			bnode* current = root, *parent = NULL;
			
			while(current != NULL)
			{
				parent = current;
				if(current->value < x)
					current = current->right;
				else if(current->value > x)
					current = current->left;
				else
					return root;
			}
			
			if(parent == NULL)
				return temp;
			else if(parent->value > x)
				parent->left = temp;
			else if(parent->value < x)
				parent->right = temp;
			
			return root;
		}
		
		bnode* recursive_delete(bnode* root, int x)
		{
			if(root == NULL)
				return root;
			else if(root->value > x)
				root->left = recursive_delete(root->left,x);
			else if(root->value < x)
				root->right = recursive_delete(root->right,x);
			
			else
			{
				if(root->left == NULL)
				{
					bnode *temp = root->right;
					delete(root);
					return temp;
				}
				else if(root->right == NULL)
				{
					bnode *temp = root->left;
					delete(root);
					return temp;
				}
				else
				{
					bnode *successor = getsuccessor(root);
					successor->value = root->value;
					root->right = recursive_delete(root->right,successor->value);
				}
				return root;
				
			}
		}
};

void binaryTree_functions()
{
	cout<<"\n"
	"1)Recursive Search\n"
	"2)Iterative search\n"
	"3)Recursive Insert\n"
	"4)Iterative Insert\n"
	"5)Recursive Delete\n\n";
}

