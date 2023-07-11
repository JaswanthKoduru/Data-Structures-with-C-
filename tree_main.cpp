#include<iostream>
#include<iomanip>

#include "tree_functions.h"

using namespace std;

int main()
{
	tree object;
	cout<<"        	           536\n\n";                   
//                             
	cout<<"        	48                    89\n\n"; 
//                               
	cout<<"\t  1         2            3         4\n\n";
	node *root = new node(536);
	root->left = new node(48);
	root->right = new node(89);
			
	root->left->left = new node(1);
	root->left->right = new node(2);
			
	root->right->left = new node(3);
	root->right->right = new node(4);	

	cout<<"\n1 -> Inorder\n2 -> Preorder\n3 -> PostOrder\n4 -> Size of tree\n5 -> Maximum value\n6 -> Height of tree\n7 -> Iterative Inorder";
	cout<<endl<<endl;
	int answer;cin>>answer;
	switch(answer)
	{
		case 1:
			{
				object.inorder(root);
			}
			break;
			
		case 2:
			{
				object.preorder(root);
			}
			break;
			
		case 3:
			{
				object.postorder(root);
			}
			break;
			
		case 4:
			{
				cout<<"size : "<<object.tree_size(root);
			}
			break;
			
		case 5:
			{
				cout<<"max value : "<<object.tree_max(root);
			}
			break;
			
		case 6:
			{
				cout<<"tree height : "<<object.tree_height(root);
			}
			break;
			
		case 7:
			{
				object.iterative_inorder(root);
			}
			break;
	}
	
}
