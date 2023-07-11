#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

void linkedlist_functions()
{
	cout<<"\n"
	"1)Insert at the beginning\n"
	"2)Insert at the end\n"
	"3)Insert at a position\n"
	"4)Delete the first node\n"
	"5)delete the last node\n"
	"6)Delete in the middle\n"
	"7)Reverse the linked list";
}

class linkedlist{
	private:
		node *head;
	public:
		linkedlist()
		{head = NULL;}
		
		void additem(int d)
		{
			node* newnode = new node;
			newnode->data = d;
			newnode->next = head;
			head = newnode;
		}
		
		void display()
		{					//display all the links
			node* current = head;
			while(current!=NULL)
			{
				cout<<current->data<<" ";
				current=current->next;
			}
		}
		
		void insert_beginning()
		{
			cout<<"\nEnter element to insert in the start : ";int x;
			cin>>x;
			
			node *newnode = new node;
			newnode->data = x;
			newnode->next = head;
			head = newnode;
		}
		
		void insert_ending()
		{
			cout<<"\nEnter element to insert at the end : ";int x;
			cin>>x;
			
			node *newnode = new node;
			newnode->data = x;
			newnode->next = NULL;
			node *current = head;
			while(current != NULL)
				current = current->next;
			
			current->next = newnode;
			
		}
		
		void insert_at_pos()
		{
			int pos,num;
			cout<<"Enter the number and the index to insert it : ";
			cin>>num>>pos;
			
			if(pos == 0)
			{
				insert_beginning();
				return;
			}
			
//			node *inode = new node();
//			inode->data = num;
//			node *current = head, *prev = NULL;
//			
//			while(pos--){
//				prev = current;
//				current = current->next;
//			}		
//			
//			inode->next = current;
//			prev->next = inode;
			
			node *current = head;
			node *nextnode;
			
			node *inode = new node;
			inode->data = num;
			
			int i=0;
			while(i<pos-1)
			{
				current = current->next;
				i++;
			}
			
			nextnode = current->next;
			inode->next = nextnode;

			current->next = inode;
			
		}
		
		void delete_beginning()
		{
			node *current = head;
			head = head->next;
			delete current;
		}
		
		void delete_ending()
		{
		
			node *current = head;
			while(current->next->next != NULL)
			{
				current = current->next;
			}
			delete current->next;
			current->next = NULL;
		}
		
		void delete_inbetween();
		
		void reverse()
		{
			node *current, *prevnode, *nextnode;
			prevnode = NULL;
			
			current = nextnode =head;
			
			while(nextnode!= NULL)
			{
				nextnode = current->next;
				current->next = prevnode;
				prevnode = current;
				current = nextnode;
			}
			head = prevnode;
		}
	
};

void linkedlist::delete_inbetween()
{
	node *current = head, *prevnode = NULL;
	cout<<"Enter the index of the node : ";
	int pos;cin>>pos;
	while(pos--)
	{
		prevnode = current;
		current = current->next;
	}
	
	prevnode->next = current->next;
	delete current;
	
	
//	int i = 1,pos;
//	cout<<"position to delete : ";cin>>pos;
//	node *current = head, *nextnode;
//	while(i<pos)
//	{
//		current = current->next;
//		i++;
//	}
//	nextnode = current->next;
//	current->next = nextnode->next;
//	delete nextnode;
}
