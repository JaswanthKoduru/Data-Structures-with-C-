#include <iostream>
#include <iomanip>
using namespace std;

#include "binaryTree_functions.h"

void binaryTrees_main()
{
	bst object;
	
	binaryTree_functions();
	
	bnode *root = new bnode(536);
	object.recursive_insert(root,48);
	object.recursive_insert(root,89);
	
	object.recursive_insert(root,10);
	object.recursive_insert(root,20);
	object.recursive_insert(root,30);
	object.recursive_insert(root,40);
	
	cout<<setw(30)<<"536"<<endl<<endl;
	cout<<setw(20)<<"48"<<setw(20)<<"89"<<endl<<endl;
	cout<<setw(15)<<"10"<<setw(10)<<"20"<<setw(10)<<"30"<<setw(10)<<"40"<<endl<<endl;
	
	cout<<"inorder of the tree is : "; 
	object.inorder(root);
	
	cout<<"\n\nEnter the function to perform : ";
	int answer;cin>>answer;
	int val;
	
	switch(answer)
	{
		case 1:
			cout<<"Enter the value to search: ";
			cin>>val;
			cout<<object.recursive_search(root,val);
			break;
		
		case 2:
			cout<<"Enter the value to search: ";
			cin>>val;
			cout<<object.iterative_search(root,val);
			break;
			
		case 3:
			cout<<"Enter the value to insert: ";
			cin>>val;
			root = object.recursive_insert(root,val);
			cout<<"inorder of the tree is : "; 
			object.inorder(root);
			break;
		
		case 4:
			cout<<"Enter the value to insert: ";
			cin>>val;
			root = object.Iterative_insert(root,val);
			cout<<"inorder of the tree is : "; 
			object.inorder(root);
			break;
			
		case 5:
			cout<<"Enter the value to delete: ";
			cin>>val;
			root = object.recursive_delete(root,val);
			cout<<"inorder of the tree is : "; 
			object.inorder(root);
			break;			
	}
}
