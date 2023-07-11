#include<iostream>
#include<iomanip>

#include "tree_functions.h"

using namespace std;

void trees_main()
{
	tree object;
	
	cout<<"\n\n";
	cout<<setw(22)<<"        536";                   
	cout<<"\n\n";                             
	cout<<"         48                     89"; 
	cout<<"\n\n"; 
	cout<<"     1       2               3       4";
	cout<<"\n";
	
	tnode *root = new tnode(536);
	
	root->left = new tnode(48);
	root->right = new tnode(89);
			
	root->left->left = new tnode(1);
	root->left->right = new tnode(2);
			
	root->right->left = new tnode(3);
	root->right->right = new tnode(4);	

	tree_functions();
	
	cout<<"Enter your choice: ";
	int answer;cin>>answer;
	switch(answer)
	{
		case 1:
			object.inorder(root);			
			break;
			
		case 2:
			object.preorder(root);
			break;
			
		case 3:
			object.postorder(root);
			break;
			
		case 4:
			cout<<"size of the tree is: "<<object.tree_size(root);
			break;
			
		case 5:
			cout<<"max value in the tree is: "<<object.tree_max(root);
			break;
			
		case 6:
			cout<<"height of the tree is: "<<object.tree_height(root);
			break;
			
		case 7:
			object.iterative_inorder(root);
			break;
	}
}
