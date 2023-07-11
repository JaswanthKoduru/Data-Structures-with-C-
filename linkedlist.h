#include<iostream>
#include<iomanip>
#include "linkedlist_function.h"

using namespace std;

void linkedlist_main()
{
	linkedlist obj;
	obj.additem(10);  obj.additem(20);  obj.additem(30);  obj.additem(40);  obj.additem(50);
	
	linkedlist_functions();
	cout<<"\n\nLinked List : ";obj.display();
	cout<<"\nEnter the function to perform : ";
	int answer;cin>>answer;
	switch(answer)
	{
		case 1:
			obj.insert_beginning();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 2:
			obj.insert_ending();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 3:
			obj.insert_at_pos();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 4:
			obj.delete_beginning();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 5:
			obj.delete_ending();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 6:
			obj.delete_inbetween();
			cout<<"The updated array is : ";obj.display();
			break;
			
		case 7:
			obj.reverse();
			cout<<"The updated array is : ";obj.display();
			break;
		
		default:
			cout<<"\nInvalid input\nPlease enter an input from 1-7";
			break;
	}
}
